#include "sortfiltertablemodel.h"

Models::SortFilterTableModel::SortFilterTableModel(QObject *parent)
    : QSortFilterProxyModel(parent), _isReverseFullName(false)
{
}

bool Models::SortFilterTableModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex index0 = sourceModel()->index(source_row, 0, source_parent);
    QModelIndex index1 = sourceModel()->index(source_row, 1, source_parent);
    QModelIndex index2 = sourceModel()->index(source_row, 2, source_parent);
    QModelIndex index3 = sourceModel()->index(source_row, 3, source_parent);
    QModelIndex index4 = sourceModel()->index(source_row, 4, source_parent);

    return sourceModel()->data(index0).toString().contains(filterRegularExpression()) ||
           sourceModel()->data(index1).toString().contains(filterRegularExpression()) ||
           sourceModel()->data(index2).toString().contains(filterRegularExpression()) ||
           sourceModel()->data(index3).toString().contains(filterRegularExpression()) ||
           sourceModel()->data(index4).toString().contains(filterRegularExpression());
}

bool Models::SortFilterTableModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    return source_left.data().toString() < source_right.data().toString();
}

QVariant Models::SortFilterTableModel::data(const QModelIndex &index, int role) const
{
    QModelIndex sourceIndex = this->mapToSource(index);

    if (index.isValid() && !sourceIndex.isValid())
    {
        return QVariant();
    }

    if (_isReverseFullName)
    {
        if (sourceIndex.column() == 1)
        {
            QString lastName = this->sourceModel()->data(sourceIndex, role).toString();
            std::reverse(lastName.begin(), lastName.end());
            return lastName;
        }

        if (sourceIndex.column() == 2)
        {
            QString firstName = this->sourceModel()->data(sourceIndex, role).toString();
            std::reverse(firstName.begin(), firstName.end());
            return firstName;
        }
    }

    return sourceModel()->data(sourceIndex, role);
}
