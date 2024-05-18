#include "highestscoreslistview.h"
#include "highestscoreslist.h"

namespace Models
{

HighestScoresListView::HighestScoresListView(QObject *parent) : QSortFilterProxyModel(parent)
{
}

bool HighestScoresListView::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (sourceRow <= 10)
    {
        return true;
    }
    return false;
}

} // namespace Models
