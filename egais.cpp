#include "egais.h"

egais::egais(QObject *parent) : QObject(parent) {
}

QString egais::getalcocode( QString axcise_mark){
    bool ok;
    QString alcocode;
    alcocode = axcise_mark.mid(3,16);
    alcocode =  alcocode.setNum(alcocode.toULongLong(&ok,36));
    while (alcocode.length()<19){
        alcocode.prepend("0");
    }
    return alcocode;
}
