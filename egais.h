#ifndef EGAIS_H
#define EGAIS_H

#include <QObject>
#include <QList>
#include "QDebug"
#include "QSqlQuery"
#include "QFile"
#include "QXmlStreamWriter"
#include "QProcess"
#include "QMessageBox"
#include "QFileDialog"

class egais : public QObject
{
    Q_OBJECT
public:
    explicit egais(QObject *parent = 0);

signals:

public slots:  
    QString getalcocode( QString axcise_mark);

};

#endif // EGAIS_H
