#include "highestscoreslist.h"
#include "comparefunctions.h"
#include <algorithm>
namespace Models
{

int HighestScoresList::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }
    return _listStudents.size();
}

QVariant HighestScoresList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return {};
    }

    if (index.row() >= _listStudents.size())
    {
        return {};
    }

    const auto &student = _listStudents[index.row()];

    switch (role)
    {
    case IdStudentRole:
        return student.GetIdStudent();
    case LastNameRole:
        return student.GetLastName();
    case FirstNameRole:
        return student.GetFirstName();
    case FullNameRole:
        return student.GetFullName();
    case IdClassRole:
        return student.GetIdClass();
    case ScoreRole:
        return student.GetScore();
    default:
        return {};
    }
}

QHash<int, QByteArray> HighestScoresList::roleNames() const
{
    return _roles;
}

bool HighestScoresList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
    {
        return false;
    }

    if (index.row() >= _listStudents.size())
    {
        return false;
    }

    auto &student = _listStudents[index.row()];

    switch (role)
    {
    case IdStudentRole:
        student.SetIdStudent(value.toString());
        break;
    case LastNameRole:
        student.SetLastName(value.toString());
        break;
    case FirstNameRole:
        student.SetFirstName(value.toString());
        break;
    case IdClassRole:
        student.SetIdClass(value.toString());
        break;
    case ScoreRole:
        student.SetScore(value.toString());
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags HighestScoresList::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

bool HighestScoresList::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; i++)
    {
        _listStudents.insert(row, {});
    }
    endInsertRows();
    return true;
}

bool HighestScoresList::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    _listStudents.remove(row, count);
    endRemoveRows();
    return true;
}

void HighestScoresList::sort(int column, Qt::SortOrder order)
{
    Q_UNUSED(column);
    emit layoutAboutToBeChanged();
    switch (order)
    {
    case Qt::AscendingOrder:
        std::sort(_listStudents.begin(), _listStudents.end(), Commons::CompareAsByStudentScore());
        break;

    case Qt::DescendingOrder:
        std::sort(_listStudents.begin(), _listStudents.end(), Commons::CompareDesByStudentScore());
        break;
    default:
        break;
    }
    emit layoutChanged();
}

HighestScoresList::HighestScoresList(QObject *parent) : QAbstractListModel(parent)
{
    _roles[IdStudentRole] = "idStudent";
    _roles[LastNameRole] = "lastName";
    _roles[FirstNameRole] = "firstName";
    _roles[FullNameRole] = "fullName";
    _roles[IdClassRole] = "idClass";
    _roles[ScoreRole] = "score";
}
} // namespace Models
