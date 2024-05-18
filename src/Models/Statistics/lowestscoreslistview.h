#ifndef LOWESTSCORESLISTVIEW_H
#define LOWESTSCORESLISTVIEW_H

#include "qqmlintegration.h"
#include <QObject>
#include <QSortFilterProxyModel>
namespace Models
{

class LowestScoresListView : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT
  public:
    explicit LowestScoresListView(QObject *parent = nullptr);

  protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
};

} // namespace Models

#endif // LOWESTSCORESLISTVIEW_H
