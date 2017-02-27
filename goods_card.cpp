#include "goods_card.h"
#include "ui_goods_card.h"
QSqlTableModel *model;
QSqlTableModel *barcode_model;
QSqlTableModel *egais_model;

goods_card::goods_card(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::goods_card){
    ui->setupUi(this);
}

goods_card::~goods_card(){
    delete ui;
}
//Строим модель по текущей карте
void goods_card::get_goods_card(QString id){
    model = new QSqlTableModel;
    // дербаним goods
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("goods");
    model->select();
    model->setFilter("code="+id);
    QModelIndex indexAlco = model->index(0,4);
    QModelIndex indexExcise = model->index(0,5);
    QModelIndex indexName = model->index(0,1);
    QModelIndex indexPrice = model->index(0,2);
    QModelIndex indexUnit = model->index(0,3);
    QModelIndex indexCode = model->index(0,6);
    QModelIndex indexGroup = model->index(0,7);
    QModelIndex indexVolume = model->index(0,8);
    barcode_model = new QSqlTableModel;
    barcode_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    barcode_model->setTable("barcode");
    barcode_model->select();
    barcode_model->setFilter("goods_id="+id);
    ui->view_barcode->setModel(barcode_model);
    ui->view_barcode->setColumnHidden(0,true);
    ui->view_barcode->setColumnHidden(1,true);

    barcode_model->setHeaderData(2, Qt::Horizontal, tr("Штрих-Код"));
    egais_model = new QSqlTableModel;
    egais_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    egais_model->setTable("tovar_egais");
    egais_model->select();
    egais_model->setFilter("good_id="+id);

    if (indexAlco.data().toString()=="1"){
        ui->alcohol->setChecked(1);
    } else {ui->alcohol->setChecked(0);}
    if (indexExcise.data().toString()=="1"){
        ui->excise->setChecked(1);
    } else {ui->excise->setChecked(0);}
    ui->goods_edit->setText(indexName.data().toString());
    ui->price_edit->setText(indexPrice.data().toString());
    ui->units_edit->setText(indexUnit.data().toString());
    ui->code_edit->setText(indexCode.data().toString());
    ui->group_edit->setText(indexGroup.data().toString());
    ui->volume_edit->setText(indexVolume.data().toString());
    ui->egais_goods->setModel(egais_model);
    ui->egais_goods->hideColumn(0);
    ui->egais_goods->hideColumn(3);
    ui->egais_goods->hideColumn(7);
    ui->egais_goods->hideColumn(8);
    ui->egais_goods->hideColumn(10);
    ui->egais_goods->hideColumn(12);
    ui->egais_goods->resizeRowsToContents();
    //ui->tableView->resizeRowsToContents(1);
    for (int i = 2 ; i <ui->egais_goods->colorCount(); i++){
        ui->egais_goods->resizeColumnToContents(i);
    }
}
void goods_card::new_goods_card(QString id){
    get_goods_card(id);
    model->insertRow(0);
    QSqlQuery getUserCode("select max(user_code) from goods");
    getUserCode.next();
    ui->code_edit->setText(QString::number(getUserCode.value(0).toInt()+1));
    ui->price_edit->setText("0");
    ui->units_edit->setText("шт");
    ui->group_edit->setText("1");
}
void goods_card::on_pushButton_3_clicked(){
    barcode_model->submitAll();
    egais_model->submitAll();
    QModelIndex indexAlco = model->index(0,4);
    QModelIndex indexExcise = model->index(0,5);
    QModelIndex indexName = model->index(0,1);
    QModelIndex indexPrice = model->index(0,2);
    QModelIndex indexUnit = model->index(0,3);
    QModelIndex indexCode = model->index(0,6);
    QModelIndex indexGroup = model->index(0,7);
    QModelIndex indexVolume = model->index(0,8);
    if (ui->alcohol->checkState()) {
        model->setData(indexAlco, "1");
    }
    if (!ui->alcohol->checkState()) {
        model->setData(indexAlco, "0");
    }
    if (ui->excise->checkState()) {
        model->setData(indexExcise, "1");
    }
    if (!ui->excise->checkState()) {
        model->setData(indexExcise, "0");
    }
    model->setData(indexName, ui->goods_edit->text());
    model->setData(indexPrice, ui->price_edit->text());
    model->setData(indexUnit, ui->units_edit->text());
    model->setData(indexCode, ui->code_edit->text());
    model->setData(indexGroup, ui->group_edit->text());
    model->setData(indexVolume, ui->volume_edit->text());
    if(!model->submitAll()){
        QMessageBox::warning(0,"Ошибка сохранения данных", model->lastError().text());
    }
    emit update();
}
void goods_card::on_add_barcode_clicked(){
    bool ok;
    //игнорировать ввод подумать как подумать что если есть не сохраненные то может и их как то проверять
    QString text = QInputDialog::getText(this, tr("Штрих код товара"),
                                         tr("Отсканируйте штрих код"), QLineEdit::Normal, tr(" "), &ok);
    QSqlQuery barcode_exist("select * from barcode where barcode="+text);
    barcode_exist.next();
    qDebug() << "Резуьтат поиска ШК " << barcode_exist.value(0).toString();
    if (ok){
        if (barcode_exist.value(0).toString()!="") {
            QMessageBox::warning(0,"Ошибка ШТРИХ-КОДА", "Данный ШК Уже используется");
        } else {
            int row=barcode_model->rowCount();
            barcode_model->insertRow(row);
            ui->view_barcode->selectRow(row);
            ui->view_barcode->setFocus();
            QString new_row_id = QString::number(row+1);
            qDebug() << "newrow " << new_row_id;
            QSqlQuery query("select max(id) from barcode");
            query.next();
            qDebug() << "id_MAX " << query.value(0).toInt();
            barcode_model->setData(barcode_model->index(row, 0), query.value(0).toInt()+1);
            QModelIndex index = model->index(0, 0);
            barcode_model->setData(barcode_model->index(row, 1), index.data(Qt::DisplayRole).toString());
            index = model->index(0, 0);
            barcode_model->setData(barcode_model->index(row, 2), text);
        }
    }
}
void goods_card::on_del_barcode_clicked(){
    ui->view_barcode->model()->removeRow(ui->view_barcode->currentIndex().row());
    barcode_model->submitAll();
}
void goods_card::on_addEgaisGood_clicked(){
    egais new_egais;
    bool ok;
    //игнорировать ввод
    QString text = QInputDialog::getText(this, tr("Акцизный товар марка"),
                                         tr("Отсканируйте акцизную марку"), QLineEdit::Normal, tr(" "), &ok);
    // если введен надходим в базе
    QString alcocode = new_egais.getalcocode(text);
    if(ok){
        qDebug() << "ALCOCDE " <<  alcocode;
        QSqlQuery find_egais_good("select * from tovar_egais where AlcCode=\'"+alcocode+"\'");
        find_egais_good.next();
        if (find_egais_good.value(0).toString()=="") {
            QMessageBox::warning(0,"Ошибка товара ЕГАИС", "Данный Товар не содержится в базе " + alcocode);
        } else {
            QSqlQuery find_goods_id("select good_id from tovar_egais where AlcCode="+alcocode);
            find_goods_id.next();
            if (find_goods_id.value(0).toString()!="") {
                QMessageBox::warning(0,"Ошибка товара ЕГС", "Данный Товар уже использован с другой нуменклатурой");
            }   else {
                egais_model->setFilter("AlcCode="+alcocode);
                QModelIndex index = model->index(0, 0);
                qDebug() << "current good ID " << index.data(Qt::DisplayRole).toString();
                int row=egais_model->rowCount();
                egais_model->setData(egais_model->index(row-1, 10), index.data(Qt::DisplayRole).toInt());
            }
        }
    }
}
void goods_card::keyPressEvent(QKeyEvent *event) {
    if (event->key()==Qt::Key_Tab) {
        QString id = "1";
        QModelIndex indexxx = ui->view_barcode->currentIndex();
        QMap<int,QVariant> id_data = ui->view_barcode->model()->itemData(indexxx);
        id = id_data[2].toString();
        qDebug() << "ID ==" << id;
    }
}
void goods_card::on_removeEgais_clicked(){
    //берем номер текущей строки
    int row =  ui->egais_goods->currentIndex().row();
    //ставим пустоту в место ID товара
    egais_model->setData(egais_model->index(row, 10), "");
    egais_model->submitAll();
}
void goods_card::on_goods_card_destroyed(){
    emit update();
}
void goods_card::on_cancel_clicked(){
    close();
}
void goods_card::on_pushButton_clicked(){
    on_pushButton_3_clicked();
    close();
}
