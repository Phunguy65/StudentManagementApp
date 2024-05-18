#ifndef LOWESTSCORESLIST_H
#define LOWESTSCORESLIST_H

#include "qqmlintegration.h"
#include "student.h"
#include <QAbstractListModel>
#include <QObject>

namespace Models
{

class LowestScoresList : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
  public:
    explicit LowestScoresList(QObject *parent = nullptr);

    enum RoleNames
    {
        IdStudentRole = Qt::UserRole + 1,
        LastNameRole,
        FirstNameRole,
        FullNameRole,
        IdClassRole,
        ScoreRole
    };

    // QAbstractItemModel interface
  public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;

  private:
    QVector<Student> _listStudents;
    QHash<int, QByteArray> _roles;
};

} // namespace Models

#endif // LOWESTSCORESLIST_H
