#ifndef SLISTTABLEMODEL_H
#define SLISTTABLEMODEL_H

#include "student.h"
#include <QAbstractTableModel>
#include <QQmlEngine>
#include <SList.hpp>
namespace Models
{

class SListTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
  public:
    explicit SListTableModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex{}) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex{}) override;

  private:
    DSALibraries::Containers::SList<Student> _slist;
};

} // namespace Models

#endif // SLISTTABLEMODEL_H
