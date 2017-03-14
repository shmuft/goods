#include <QApplication>
//#include <QTableWidget>
//#include <QtSql>
//#include <QMessageBox>
#include <good_input.h>
#include <goods_card.h>
#include <setting.h>
//#include <egais.h>

int main(int argc, char *argv[]){
//fork 28 02 2017
    QApplication a(argc, argv);
    good_input goods;
    goods.show();
    goods_card goodscard;
    setting setingWindow;
    QObject::connect(&goods,SIGNAL(showSetting()),&setingWindow,SLOT(show()));
    QObject::connect(&goods,SIGNAL(double_click(QString)),&goodscard,SLOT(show()));
    QObject::connect(&goods,SIGNAL(double_click(QString)),&goodscard,SLOT(get_goods_card(QString)));
    QObject::connect(&goods,SIGNAL(new_good(QString)),&goodscard,SLOT(show()));
    QObject::connect(&goods,SIGNAL(new_good(QString)),&goodscard,SLOT(new_goods_card(QString)));
    return a.exec();
}
