#ifndef HIGHESTSCORESLISTVIEW_H
#define HIGHESTSCORESLISTVIEW_H

#include "qqmlintegration.h"
#include <QObject>
#include <QSortFilterProxyModel>

namespace Models
{

class HighestScoresListView : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT
  public:
    explicit HighestScoresListView(QObject *parent = nullptr);

  protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
};

} // namespace Models

#endif // HIGHESTSCORESLISTVIEW_H
