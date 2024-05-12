#ifndef SORTFILTERTABLEMODEL_H
#define SORTFILTERTABLEMODEL_H
#include <QQmlEngine>
#include <QSortFilterProxyModel>
namespace Models
{
class SortFilterTableModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(bool isReverseFullName READ isReverseFullName WRITE setIsReverseFullName NOTIFY isReverseFullNameChanged)
  public:
    explicit SortFilterTableModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  public:
    bool isReverseFullName() const;
    void setIsReverseFullName(bool isReverseFullName);

  signals:
    void isReverseFullNameChanged();

  protected:
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;

  private:
    bool _isReverseFullName;
};
} // namespace Models

#endif // SORTFILTERTABLEMODEL_H
