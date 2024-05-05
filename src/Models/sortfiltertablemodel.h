#ifndef SORTFILTERTABLEMODEL_H
#define SORTFILTERTABLEMODEL_H
#include <QQmlEngine>
#include <QSortFilterProxyModel>
namespace Models
{
class SortFilterTableModel : public QSortFilterProxyModel
{
    Q_OBJECT
  public:
    explicit SortFilterTableModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;

  private:
    bool _isReverseFullName;
};
} // namespace Models

#endif // SORTFILTERTABLEMODEL_H
