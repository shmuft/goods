#include "intabstractlistmodel.h"
//#include <QAbstractListModel>

IntAbstractListModel::IntAbstractListModel(const QList<int>& list, QObject* pobj/*=0*/) : QAbstractListModel(pobj),
    m_list(list){
}
QVariant IntAbstractListModel::data(const QModelIndex &index, int nRole) const{
    if (!index.isValid()){
        return QVariant();
    }
    //если условие выполнилось то вернем первый за повросом иначе второй
    //Qt::DisplayRole - для отображения,  Qt::EditRole - для редактирования
    return (nRole==Qt::DisplayRole || nRole == Qt::EditRole) ? m_list.at(index.row()) : QVariant();
}
bool IntAbstractListModel::setData(const QModelIndex &index, const QVariant &value, int nRole){
    if(index.isValid()&&nRole==Qt::EditRole){
        m_list.replace(index.row(),value.value<int>());
        emit dataChanged(index,index);
        return true;
    }
    return false;
}
int IntAbstractListModel::rowCount(const QModelIndex &parent/*=QmodelIndex()*/) const{
    return m_list.size();
}
QVariant IntAbstractListModel::headerData(int nSection, Qt::Orientation orientation, int nRole/*=DisplayRole*/) const{
    if(nRole!=Qt::DisplayRole){
        return QVariant();
    }
    return (orientation==Qt::Horizontal) ? QString("Number"):QString::number(nSection);
}
Qt::ItemFlags IntAbstractListModel::flags(const QModelIndex &index) const{
    Qt::ItemFlags flags=QAbstractListModel::flags(index);
    return index.isValid()? (flags | Qt::ItemIsEditable) : flags;
}
