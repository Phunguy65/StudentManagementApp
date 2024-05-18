#ifndef CLISTTABLEMODEL_H
#define CLISTTABLEMODEL_H

#include "sortedmethodselections.h"
#include "student.h"
#include <DSALibraries/include/Containers/CList/CList.hpp>
#include <QAbstractTableModel>
#include <QQmlEngine>
#include <private/qitemselectionmodel_p.h>
namespace Models
{

class CListTableModel : public QAbstractTableModel
{
    Q_OBJECT
  public:
    explicit CListTableModel(QObject *parent = nullptr);

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
    ~CListTableModel();

  private:
    DSALibraries::Containers::CList<Student> _clist;
};

} // namespace Models

#endif // CLISTTABLEMODEL_H
