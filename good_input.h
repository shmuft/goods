#ifndef GOOD_INPUT_H
#define GOOD_INPUT_H

#include <QWidget>
#include <QSqlDatabase>
#include "QSqlQueryModel"
#include "QSqlTableModel"
#include "QSqlQuery"
#include "QDebug"
#include "QKeyEvent"
#include "egais.h"
#include "QFileDialog"
#include "QXmlStreamReader"
#include "QSqlError"
#include "QMessageBox"
#include "QTextStream"
#include "QSettings"

namespace Ui {
class good_input;
}

class good_input : public QWidget{
    Q_OBJECT
public:
    explicit good_input(QWidget *parent = 0);
    ~good_input();
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
signals:
    void double_click(QString id);
    void new_good(QString id);
    void show_card();
    void showSetting();
private slots:
    void on_pushButton_clicked();
 //   void on_tableView_clicked(const QModelIndex &index);
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_selectfile_clicked();
    void on_load_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_resetFind_clicked();

    void on_settings_clicked();

public slots:
    void load_data();
private:
    Ui::good_input *ui;
public slots:
    void updateForm();
};

#endif // GOOD_INPUT_H
