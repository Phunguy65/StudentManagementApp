#include "sortfiltertablemodel.h"

Models::SortFilterTableModel::SortFilterTableModel(QObject *parent)
    : QSortFilterProxyModel(parent), _isReverseFullName(false)
{
}

QVariant Models::SortFilterTableModel::data(const QModelIndex &index, int role) const
{
    QModelIndex sourceIndex = this->mapToSource(index);

    if (index.isValid() && !sourceIndex.isValid())
    {
        return QVariant();
    }

    if (this->isReverseFullName() && role == Qt::DisplayRole)
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

bool Models::SortFilterTableModel::isReverseFullName() const
{
    return _isReverseFullName;
}

void Models::SortFilterTableModel::setIsReverseFullName(bool isReverseFullName)
{
    if (_isReverseFullName == isReverseFullName)
    {
        return;
    }

    _isReverseFullName = isReverseFullName;
}
