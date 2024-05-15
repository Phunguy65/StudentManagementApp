#ifndef DLISTTABLEMODEL_H
#define DLISTTABLEMODEL_H

#include "sortedmethodselections.h"
#include "student.h"
#include <../DSALibraries/include/Containers/DList/DList.hpp>
#include <QAbstractTableModel>
#include <QQmlEngine>
namespace Models
{

class DListTableModel : public QAbstractTableModel
{
    Q_OBJECT
  public:
    explicit DListTableModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex{}) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex{}) override;
    void dsaSort(int column, SortMethods::SortTypes sortType, Qt::SortOrder order);
    ~DListTableModel();

  private:
    DSALibraries::Containers::DList<Student> _dlist;
};

} // namespace Models

#endif // DLISTTABLEMODEL_H
