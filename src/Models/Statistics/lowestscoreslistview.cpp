#include "lowestscoreslistview.h"

namespace Models
{

LowestScoresListView::LowestScoresListView(QObject *parent) : QSortFilterProxyModel(parent)
{
}

bool LowestScoresListView::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (sourceRow <= 10)
    {
        return true;
    }

    return false;
}

} // namespace Models
