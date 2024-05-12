#include "clisttablemodel.h"

namespace Models
{

CListTableModel::CListTableModel(QObject *parent) : QAbstractTableModel{parent}
{
}

int CListTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _clist.GetSize();
}

int CListTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 5;
}

QVariant CListTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        auto it = _clist.GetConstBegin();
        auto idx = index.row();

        while (idx-- > 0 && it.PointerNext() != _clist.GetConstEnd())
        {
            ++it;
        }

        if (it == _clist.GetConstEnd())
            return QVariant();

        auto &student = *it;

        switch (index.column())
        {
        case 0:
            return QString::fromStdString(student.GetIdStudent());
        case 1:
            return QString::fromStdString(student.GetLastName());
        case 2:
            return QString::fromStdString(student.GetFirstName());
        case 3:
            return QString::fromStdString(student.GetIdClass());
        case 4:
            return QString::fromStdString(student.GetScore());
        default:
            return QVariant();
        }
    }

    return QVariant();
}

QVariant CListTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return "ID Student";
            case 1:
                return "Last Name";
            case 2:
                return "First Name";
            case 3:
                return "ID Class";
            case 4:
                return "Score";
            default:
                return QVariant();
            }
        }
    }

    return QVariant();
}

bool CListTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    auto it = _clist.GetBegin();
    auto idx = index.row();

    while (idx-- > 0 && it.PointerNext() != _clist.GetEnd())
    {
        ++it;
    }

    if (it == _clist.GetEnd())
        return false;

    auto &student = *it;

    switch (index.column())
    {
    case 0:
        student.SetIdStudent(value.toString().toStdString());
        break;
    case 1:
        student.SetLastName(value.toString().toStdString());
        break;
    case 2:
        student.SetFirstName(value.toString().toStdString());
        break;
    case 3:
        student.SetIdClass(value.toString().toStdString());
        break;
    case 4:
        student.SetScore(value.toString().toStdString());
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags CListTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

bool CListTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);

    auto it = _clist.GetEnd();
    auto idx = row;

    while (idx-- > 0)
    {
        if (it.PointerNext() == _clist.GetEnd())
        {
            break;
        }
        ++it;
    }

    while (count-- > 0)
    {
        it = _clist.InsertAfter(it, Student());
    }

    endInsertRows();
    return true;
}

bool CListTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);

    auto it = _clist.GetEnd();
    auto idx = row;

    while (idx-- > 0)
    {
        if (it.PointerNext() == _clist.GetEnd())
        {
            break;
        }
        ++it;
    }

    while (count-- > 0)
    {
        if (it == _clist.GetEnd())
        {
            break;
        }
        it = _clist.EraseAfter(it);
    }

    endRemoveRows();
    return true;
}

CListTableModel::~CListTableModel()
{
    qDebug() << "CListTableModel deleted";
}

} // namespace Models
