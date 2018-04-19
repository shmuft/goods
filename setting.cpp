#include "setting.h"
#include "ui_setting.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QSqlTableModel>

 QSettings *settings = new QSettings("settings.conf",QSettings::IniFormat);

setting::setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    ui->lineEdit->setText(settings->value("database/path").toString());
    ui->version->setText(settings->value("main/version").toString());
     QSqlTableModel *modelSetting= new QSqlTableModel;
    modelSetting->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelSetting->setTable("device");
    modelSetting->select();

    ui->setting_view->setModel(modelSetting);
        ui->setting_view->hideColumn(0);
        ui->setting_view->hideColumn(5);
        ui->setting_view->hideColumn(6);
         modelSetting->setHeaderData(1, Qt::Horizontal, tr("Активность ФР, 1-активен"));
         modelSetting->setHeaderData(2, Qt::Horizontal, tr("Название организации"));
         modelSetting->setHeaderData(3, Qt::Horizontal, tr("Тип оборудования"));
         modelSetting->setHeaderData(4, Qt::Horizontal, tr("Производитель"));

}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Открыть файл БД"),"",tr("SqlLiteБД (*.db);"));
        if (fileName !=""){
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)){
                QMessageBox::critical(this,tr("Error"),tr("Could not open file"));
                return;
            } else {
                file.close();
                ui->lineEdit->setText(fileName);
            }
         //   QTextStream in(&file);
         //   textEdt->setText(in.readAll());
         //   file.close();
        }
}

void setting::on_pushButton_2_clicked()
{
    ui->setting_view->model()->submit();
    settings->setValue("database/path",ui->lineEdit->text());
}
