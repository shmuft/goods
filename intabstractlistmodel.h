#ifndef INTABSTRACTLISTMODEL_H
#define INTABSTRACTLISTMODEL_H

//#include <QObject>
#include <QAbstractListModel>

class IntAbstractListModel : public QAbstractListModel{
    Q_OBJECT
private:
    QList<int> m_list;
public:
 //  explicit IntAbstractListModel(QObject *parent = 0);
 // explicit
    IntAbstractListModel(const QList<int>& list, QObject* pobj=0);
    //get data
    QVariant data(const QModelIndex& index, int nRole) const;
    //set data
    bool setData(const QModelIndex &index, const QVariant &value, int nRole);
    int rowCount(const QModelIndex& parent=QModelIndex()) const;
    QVariant headerData(int nSection, Qt::Orientation orientation, int nRole=Qt::DisplayRole ) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
signals:

public slots:
};

#endif // INTABSTRACTLISTMODEL_H
