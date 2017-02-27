#include "good_input.h"
#include "ui_good_input.h"


good_input::good_input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::good_input){
    ui->setupUi(this);
    dbase.setDatabaseName("main.db");
    if (!dbase.open()) {
        QMessageBox::warning(0,"Проблемы с БД", dbase.lastError().text());
    }
    load_data();
    ui->tableView->setFocus();
}
good_input::~good_input(){
    delete ui;
}
void good_input::load_data(){
    QSqlTableModel *model= new QSqlTableModel;
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setTable("goods");
    model->select();
    ui->tableView->setModel(model);
    for (int i=0; i<30; i++){
        ui->tableView->scrollTo(ui->tableView->model()->index( ui->tableView->model()->rowCount()-1,1));
    }
    ui->tableView->hideColumn(0);
    model->setHeaderData(1, Qt::Horizontal, tr("Наименование"));
    model->setHeaderData(2, Qt::Horizontal, tr("Цена"));
    model->setHeaderData(3, Qt::Horizontal, tr("Единицы \n измерения"));
    model->setHeaderData(4, Qt::Horizontal, tr("Алкогольный"));
    model->setHeaderData(5, Qt::Horizontal, tr("Акцизный"));
    model->setHeaderData(6, Qt::Horizontal, tr("Код"));
    model->setHeaderData(7, Qt::Horizontal, tr("Группа \n печати"));
    model->setHeaderData(8, Qt::Horizontal, tr("Обьем"));
    ui->tableView->resizeRowsToContents();
    //ui->tableView->resizeRowsToContents(1);
    for (int i = 2 ; i <=8; i++){
        ui->tableView->resizeColumnToContents(i);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
}
//вставка нового товара
void good_input::on_pushButton_clicked(){    
    QSqlQuery get_max_id("select max(code) from goods");
    get_max_id.next();
    QString maxid = QString::number(get_max_id.value(0).toInt()+1);
    emit new_good(maxid);
}
//шк формируем

//плюнемся id товара в следующий виджет, там уже отработаем
void good_input::on_tableView_doubleClicked(const QModelIndex &index){
    QString id = "1";
    QModelIndex indexxx = ui->tableView->model()->index(index.row(),0);
    QMap<int,QVariant> id_data = ui->tableView->model()->itemData(indexxx);
    id = id_data[0].toString();
    qDebug() << "ID ==" << id;
    emit double_click(id);
    //здесь опишем механизм передачи информации в еще одно окно информации.
}
void good_input::updateForm(){
    emit update();
}
void good_input::on_pushButton_3_clicked(){
    qDebug() << "row count" <<  ui->tableView->model()->rowCount();

    load_data();
     on_resetFind_clicked();
}
//remove row удаление
void good_input::on_pushButton_4_clicked(){
    QModelIndex indexxx = ui->tableView->model()->index(ui->tableView->currentIndex().row(),0);
    QMap<int,QVariant> id_data = ui->tableView->model()->itemData(indexxx);
    qDebug() << "goods_id" << id_data[0].toString();
    QSqlQuery deleteSHK("DELETE FROM barcode WHERE goods_id='"+id_data[0].toString()+"'");
    deleteSHK.exec();
    ui->tableView->model()->removeRow(ui->tableView->currentIndex().row());
    load_data();
}
void good_input::on_selectfile_clicked(){
    QString str = QFileDialog::getOpenFileName(0, "Set a Directory", ui->filename->text());
    if (!str.isEmpty()) ui->filename->setText(str);
}
//загрузка товаров в БД
void good_input::on_load_clicked(){
    QList<QStringList> goods;
    QStringList row;
    QFile file(ui->filename->text());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream filestream(&file);
    filestream.setCodec("cp1251");
    QString str;
    int dotcount=0;
    QString temp, code, barcode, name, price, group, gropOrGood;
    //create goods list
    while (!filestream.atEnd()) {
        str =  filestream.readLine();
        temp.clear();
        dotcount=0;
        if (str[1]!='#'&&str.length()>1&&str[0]!='#'&&str[0]!='<'&&str[0]!='*'&&str[0]!='+'&&str[0]!=']') {
            for (int i=0; i<str.length();i++){
                if (str[i]==';') {
                    dotcount++;
                    if(dotcount==1) {code=temp; temp.clear();}
                    if(dotcount==2) {barcode=temp; temp.clear(); }
                    if(dotcount==3) {name=temp; temp.clear(); }
                    if(dotcount==4) {temp.clear(); }
                    if(dotcount==5) {price=temp; temp.clear(); }
                    if(dotcount==8) {temp.clear(); }
                    if(dotcount==9) {group=temp; temp.clear(); }
                    if(dotcount==16) {temp.clear(); }
                    if(dotcount==17) { gropOrGood=temp; temp.clear();}
                } else {
                    temp=temp+str[i];
                }
            }
            if (gropOrGood=="1"){
                row.clear();
                if (code.length()>=6){

                    price="0";
                    code.remove(0,code.length()-5);
                    int codeDec=code.toInt();
                    code = QString::number(codeDec);
                }
                if (group=="") {group="0";}
                row << code << barcode << name << price << group;
                qDebug() << "row_foud" << row;
                goods << row;
            } else {row.clear();}
        }
    }
    file.close();
    //добавлем товары и шк
    for (int i=0;i<goods.length();i++) {
        row = goods[i];
        qDebug() << "goods_row" << row;
        QString test = "update goods set name='"+row[2]+"' ,price='"+row[3] +"',group_print='"+row[4] +"' where user_code="+row[0];
        QSqlQuery update(test);
        qDebug() << "SQL UPDATE" << update.exec(0);
        QSqlQuery find("select name from goods where user_code="+row[0]);
        if (!find.next()){
            QSqlQuery query;
            query.prepare("INSERT INTO goods (name, price, units, alc, excise, user_code, group_print ) "
                          "VALUES (:name, :price, :units, :alc, :excise, :user_code, :group_print)");
            query.bindValue(":name", row[2]);
            query.bindValue(":price", row[3]);
            query.bindValue(":units", "шт");
            query.bindValue(":alc", "0");
            query.bindValue(":excise", "0");
            query.bindValue(":user_code", row[0]);
            query.bindValue(":group_print", row[4]);
            query.exec();
            QSqlQuery getMaxId("select max(code) from goods");
            getMaxId.next();
            QSqlQuery query_barcode;
            query_barcode.prepare("INSERT INTO barcode (goods_id, barcode ) "
                                  "VALUES (:goods_id, :barcode)");
            query_barcode.bindValue(":goods_id", getMaxId.value(0).toString());
            query_barcode.bindValue(":barcode", row[1]);
            query_barcode.exec();
        }
    }
    //Дополнительные ШК
    QList<QStringList> barcods;
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    while (!filestream.atEnd()) {
        str =  filestream.readLine();
        temp.clear();
        dotcount=0;
        if (str[0]=='#'&&str.length()>1&&str[1]!='#'){

            for(int i=1; i<str.length(); i++){
                if (str[i]==';') {
                    dotcount++;
                    if(dotcount==1) {code=temp; temp.clear();}
                    if(dotcount==2) {barcode=temp; temp.clear(); }
                } else {
                    temp=temp+str[i];
                }
            }
            row.clear();
            if (code.length()>=6){

                price="0";
                code.remove(0,code.length()-5);
                int codeDec=code.toInt();
                code = QString::number(codeDec);
            }
            row << code << barcode;
            barcods << row;
        }
    }
    // дополнительные ШК вставка
    for (int i=0;i<barcods.length();i++) {
        row = barcods[i];
        QSqlQuery dopShc("select barcode from barcode where barcode="+row[1]);
        if (!dopShc.next()){
            QString text="select code from goods where user_code="+row[0];
            QSqlQuery getgoodsid(text);
            getgoodsid.next();
            QSqlQuery query_barcode;
            query_barcode.prepare("INSERT INTO barcode (goods_id, barcode ) "
                                  "VALUES (:goods_id, :barcode)");
            query_barcode.bindValue(":goods_id",getgoodsid.value(0).toString() );
            query_barcode.bindValue(":barcode", row[1]);
            query_barcode.exec();
        }
    }
    //алкоголь
    QList<QStringList> alcolist;
    file.close();
    file.open(QIODevice::ReadOnly);
    row.clear();
    bool alcoFind=false;
    int rowcount=0;
    QString goodCode="0", productGroup="0", capacity="0", status="0", volume="0", alcCode="0";
    while (!filestream.atEnd()) {
        rowcount++;
        str =  filestream.readLine();
        QXmlStreamReader xmlfile(str);
        if (str[0]=='<'){
            qDebug() << "found_tag";
            while (xmlfile.readNextStartElement()) {
                QXmlStreamAttributes attributes = xmlfile.attributes();
                if (attributes.value("attr_id").toString()=="30"){
                    if (attributes.hasAttribute("id")) {
                        alcCode = xmlfile.readElementText();
                        row << goodCode << productGroup << capacity << status << volume << alcCode;
                        goodCode="0"; productGroup="0"; capacity="0"; status="0"; volume="0"; alcCode="0";
                        alcolist << row;
                        qDebug() << "Row found" << row;
                        qDebug() << "Row Count" << rowcount;
                        row.clear();
                        alcoFind=false;
                    }
                }
                if (attributes.value("attr_id").toString()=="24"){
                    if (attributes.hasAttribute("id")) {
                        status= xmlfile.readElementText();
                        alcoFind=true;
                    }
                }
                if (attributes.value("attr_id").toString()=="23"){
                    if (attributes.hasAttribute("id")) {
                        capacity = xmlfile.readElementText();
                        alcoFind=true;
                    }
                }
                if (attributes.value("attr_id").toString()=="27"){
                    if (attributes.hasAttribute("id")) {
                        volume = xmlfile.readElementText();
                        alcoFind=true;
                    }
                }
                if (attributes.value("attr_id").toString()=="22"){
                    if (attributes.hasAttribute("id")) {
                        goodCode = attributes.value("id").toString();
                        if (goodCode.length()>=6){

                            price="0";
                            goodCode.remove(0,goodCode.length()-5);
                            int codeDec=goodCode.toInt();
                            goodCode = QString::number(codeDec);
                        }
                        productGroup = xmlfile.readElementText();
                        alcoFind=true;
                    }
                }
            }
        }
        if ((filestream.atEnd()||str[0]!='<')&&alcoFind==true){
            row << goodCode << productGroup << capacity << status << volume << alcCode;
            goodCode="0"; productGroup="0"; capacity="0"; status="0"; volume="0"; alcCode="0";
            alcolist << row;
            qDebug() << "Row found" << row;
            qDebug() << "Row Count" << rowcount;
            row.clear();
            alcoFind=false;
        }
    }
    int countInsertedRows=0;
    for (int i=0;i<alcolist.length();i++) {

        QString alcCodeInsert;

        row = alcolist[i];
        alcCodeInsert=row[5];
        qDebug() << "insert row" << row;
        //поиск алкокодов row[5]

        if (alcCodeInsert.length()<=19&&alcCodeInsert!="0") {
            QString text="select code, name from goods where user_code="+row[0];
            QSqlQuery getgoodsid(text);
            getgoodsid.next();
            if (alcCodeInsert!="0"){
                QString update="update tovar_egais set good_id="+getgoodsid.value(0).toString()+" where AlcCode='"+alcCodeInsert+"'";
                QSqlQuery query_barcode(update);
                query_barcode.next();
            }
            QSqlQuery find("select good_id from tovar_egais where AlcCode='"+alcCodeInsert+"'");
            find.next();
            qDebug() << "alco_insert_query" << find.value(0).toString();
            if (find.value(0).toString()==""){
                countInsertedRows++;
                QSqlQuery query;
                query.prepare("INSERT INTO tovar_egais ( AlcCode, FullName, Capacity, AlcVolume, ProductVCode, Type, good_id, Pack_ID ) "
                              "VALUES ( :AlcCode, :FullName, :Capacity, :AlcVolume, :ProductVCode, :Type, :good_id, :Pack_ID)");
                query.bindValue(":AlcCode", alcCodeInsert);
                query.bindValue(":FullName", getgoodsid.value(1).toString());
                query.bindValue(":Capacity", row[2]);
                query.bindValue(":AlcVolume",row[4]);
                query.bindValue(":ProductVCode", row[1]);
                query.bindValue(":Type", "АП");
                query.bindValue(":good_id", getgoodsid.value(0).toString());
                query.bindValue(":Pack_ID","0");
                query.exec();
                qDebug() << "error query" << query.lastError();
            }
        } else {
            //берем с первого символа 19 элементов, с ними работаем,
            //потом укорачиваем строку на 21 символов (","+" ")
            while (alcCodeInsert.length()>19) {
                QString alcCodeInsertTemp;
                for (int i=0; i<19; i++){
                    alcCodeInsertTemp[i]=alcCodeInsert[i];
                }
                alcCodeInsert.remove(0,21);
                qDebug() << "alcoinsert" << alcCodeInsertTemp;
                QString text="select code, name from goods where user_code="+row[0];
                QSqlQuery getgoodsid(text);
                getgoodsid.next();
                if (alcCodeInsertTemp!="0"){
                    QString update="update tovar_egais set good_id="+getgoodsid.value(0).toString()+" where AlcCode='"+alcCodeInsertTemp+"'";
                    QSqlQuery query_barcode(update);
                    query_barcode.next();
                }
                QSqlQuery find("select good_id from tovar_egais where AlcCode='"+alcCodeInsertTemp+"'");
                find.next();
                qDebug() << "insert" << find.value(0).toString();
                if (find.value(0).toString()==""){
                    countInsertedRows++;
                    QSqlQuery query;
                    query.prepare("INSERT INTO tovar_egais ( AlcCode, FullName, Capacity, AlcVolume, ProductVCode, Type, good_id, Pack_ID ) "
                                  "VALUES ( :AlcCode, :FullName, :Capacity, :AlcVolume, :ProductVCode, :Type, :good_id, :Pack_ID)");
                    query.bindValue(":AlcCode", alcCodeInsert);
                    query.bindValue(":FullName", getgoodsid.value(1).toString());
                    query.bindValue(":Capacity", row[2]);
                    query.bindValue(":AlcVolume",row[4]);
                    query.bindValue(":ProductVCode", row[1]);
                    query.bindValue(":Type", "АП");
                    query.bindValue(":good_id", getgoodsid.value(0).toString());
                    query.bindValue(":Pack_ID","0");
                    query.exec();
                    qDebug() << "error query" << query.lastError();
                }
            }
        }
        QSqlQuery alcohol("update goods set alc=\'1\' where user_code="+row[0]);
        alcohol.next();
        if (row[3]=="0"){
            QSqlQuery excise("update goods set excise=\'1\' where user_code="+row[0]);
            excise.next();
        } else {
            QSqlQuery excise("update goods set excise=\'0\' where user_code="+row[0]);
            excise.next();
        }
        QString volumeQuery="update goods set volume=\'"+row[2] +"\' where user_code="+row[0];
        QSqlQuery volume(volumeQuery);
        qDebug() << "volume_set" << volume.next() << volumeQuery;

    }
    QMessageBox::warning(0,"Добавлено товаров ЕГАИС", QString::number(countInsertedRows)+" Строк добавлено");
}
void good_input::on_pushButton_9_clicked(){
    bool findExp=false;
    QString name, code;
    QString find=ui->lineEdit->text();
    find =  find.toLower();
    QTextStream cout(stdout);
  //  QList<QModelIndex> indexlist;
    for (int i=0;i<  ui->tableView->model()->rowCount();i++){
        findExp=false;
        name = ui->tableView->model()->data(ui->tableView->model()->index(i,1)).toString();
        name = name.toLower();
        int j = 0;
        while ((j = name.indexOf(find, j)) != -1) {
            qDebug() << name;
            qDebug() << "Found   at index position" << j;
            ++j;
            findExp=true;
        //    indexlist << ui->tableView->model()->index(i+10,1);
            ui->tableView->scrollTo(ui->tableView->model()->index(i+10,1));
            ui->tableView->setCurrentIndex(ui->tableView->model()->index(i,1));
        }
        code = ui->tableView->model()->data(ui->tableView->model()->index(i,6)).toString();
        code = code.toLower();
        j = 0;
        while ((j = code.indexOf(find, j)) != -1) {
            ++j;
            findExp=true;
      //      indexlist << ui->tableView->model()->index(i+10,6);
            ui->tableView->scrollTo(ui->tableView->model()->index(i+10,6));
            ui->tableView->setCurrentIndex(ui->tableView->model()->index(i,6));
        }
        if (findExp==false) {
            ui->tableView->hideRow(i);
        }
    }
}
// поиск по подстроке в имени
void good_input::on_pushButton_10_clicked(){
    bool findExp=false;
    QString name, code;
    QString find=ui->lineEdit->text();
    find =  find.toLower();
  //  QList<QModelIndex> indexlist;
    for (int i=0;i<  ui->tableView->model()->rowCount();i++){
        findExp=false;
        int j = 0;
        code = ui->tableView->model()->data(ui->tableView->model()->index(i,6)).toString();
        code = code.toLower();
        while ((j = code.indexOf(find, j)) != -1) {
            ++j;
            findExp=true;
           // indexlist << ui->tableView->model()->index(i+10,6);
            ui->tableView->scrollTo(ui->tableView->model()->index(i+10,6));
            ui->tableView->setCurrentIndex(ui->tableView->model()->index(i,6));
        }
        if (findExp==false) {
            ui->tableView->hideRow(i);
        }
    }
}
//поиск по ШК
void good_input::on_pushButton_11_clicked(){
  qDebug() << "dfgdfg";
    QStringList findId;

    int rowCount=ui->tableView->model()->rowCount();
    QString find=ui->lineEdit->text();
    QString barcode;
    QSqlQuery selectAllBarcode("select * from barcode");
    qDebug() << "test1";
    while (selectAllBarcode.next()) {
        barcode=selectAllBarcode.value(2).toString();
        int j=0;
        while ((j = barcode.indexOf(find, j)) != -1) {
            ++j;
            //findExp=true;
            findId << selectAllBarcode.value(1).toString();
        }
    }
    int id=0;
    qDebug() << "leng" <<findId.length();
    if (findId.length()!=0){
        qDebug() << "input cycle";
    for (int i=0; i<rowCount;i++)     {
        qDebug() << "ids" << findId[id];
        if ((findId[id])==ui->tableView->model()->data(ui->tableView->model()->index(i,0)).toString()){
           if (id<(findId.length()-1)){
           id++;
           }
        } else {
            ui->tableView->hideRow(i);
        }
    }
    } else   QMessageBox::warning(0,"Шк не найден", "Штрих-Код " + find + " Не найден" );

    find.clear();
    findId.clear();
}
void good_input::on_resetFind_clicked(){
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
    for (int i=0; i<ui->tableView->model()->rowCount();i++)    {
        //  qDebug() << i;
        ui->tableView->showRow(i);
    }
}
