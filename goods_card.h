#ifndef GOODS_CARD_H
#define GOODS_CARD_H
#include "egais.h"
#include <QWidget>
#include <QKeyEvent>
#include "QSqlTableModel"
#include "QSqlQueryModel"
#include "QSqlTableModel"
#include "QSqlError"
#include "QDebug"
#include "QSqlQuery"
#include <QInputDialog>
#include <QMessageBox>
#include <QCheckBox>
#include <QStandardItem>

namespace Ui {
class goods_card;
}

class goods_card : public QWidget
{
    Q_OBJECT

public:
    explicit goods_card(QWidget *parent = 0);
    ~goods_card();
signals:
    void update();

private:
    Ui::goods_card *ui;

public slots:
    void get_goods_card(QString id);
    void new_goods_card(QString id);

private slots:
    void on_pushButton_3_clicked();
    void on_add_barcode_clicked();
    void on_del_barcode_clicked();
    void on_addEgaisGood_clicked();
    void on_removeEgais_clicked();
    void on_goods_card_destroyed();
    void on_cancel_clicked();

    void on_pushButton_clicked();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // GOODS_CARD_H
