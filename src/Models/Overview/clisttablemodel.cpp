#include "clisttablemodel.h"
#include "comparefunctions.h"
#include "sortedmethodselections.h"

namespace Models
{

CListTableModel::CListTableModel(QObject* parent) : QAbstractTableModel{parent}
{
}

int CListTableModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return _clist.GetSize();
}

int CListTableModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return 5;
}

QVariant CListTableModel::data(const QModelIndex& index, int role) const
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

        auto& student = *it;

        switch (index.column())
        {
        case 0:
            return student.GetIdStudent();
        case 1:
            return student.GetLastName();
        case 2:
            return student.GetFirstName();
        case 3:
            return student.GetIdClass();
        case 4:
            return student.GetScore();
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

bool CListTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
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

    auto& student = *it;

    switch (index.column())
    {
    case 0:
        student.SetIdStudent(value.toString());
        break;
    case 1:
        student.SetLastName(value.toString());
        break;
    case 2:
        student.SetFirstName(value.toString());
        break;
    case 3:
        student.SetIdClass(value.toString());
        break;
    case 4:
        student.SetScore(value.toString());
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags CListTableModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

bool CListTableModel::insertRows(int row, int count, const QModelIndex& parent)
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

bool CListTableModel::removeRows(int row, int count, const QModelIndex& parent)
{
    beginRemoveRows(parent, row, row + count - 1);

    auto it = _clist.GetEnd();

    for (int i = 0; i < row; ++i)
    {
        if (it.PointerNext() != _clist.GetEnd())
        {
            ++it;
        }
    }

    for (int i = 0; i < count; ++i)
    {
        if (it.PointerNext() != _clist.GetEnd())
        {
            _clist.EraseAfter(it);
        }
    }
    endRemoveRows();
    return true;
}

void CListTableModel::dsaSort(int column, SortMethods::SortTypes sortType, Qt::SortOrder order)
{
    if (order == Qt::AscendingOrder)
    {
        switch (column)
        {
        case 0: {
            _clist.DSASort((unsigned)sortType, Commons::CompareAsByStudentId());
            break;
        }
        case 1: {
            _clist.DSASort((unsigned)sortType, Commons::CompareAsByStudentLastName());
            break;
        }
        case 2: {
            _clist.DSASort((unsigned)sortType, Commons::CompareAsByStudentFirstName());
            break;
        }
        case 3: {
            _clist.DSASort((unsigned)sortType, Commons::CompareAsByStudentClassId());
            break;
        }
        case 4: {
            _clist.DSASort((unsigned)sortType, Commons::CompareAsByStudentScore());
            break;
        }
        default:
            break;
        }
    }
    else
    {
        switch (column)
        {
        case 0: {
            _clist.DSASort((unsigned)sortType, Commons::CompareDesByStudentId());
            break;
        }
        case 1: {
            _clist.DSASort((unsigned)sortType, Commons::CompareDesByStudentLastName());
            break;
        }
        case 2: {
            _clist.DSASort((unsigned)sortType, Commons::CompareDesByStudentFirstName());
            break;
        }
        case 3: {
            _clist.DSASort((unsigned)sortType, Commons::CompareDesByStudentClassId());
            break;
        }
        case 4: {
            _clist.DSASort((unsigned)sortType, Commons::CompareDesByStudentScore());
            break;
        }
        default:
            break;
        }
    }
    emit layoutChanged();
}

CListTableModel::~CListTableModel()
{
    qDebug() << "CListTableModel deleted";
}

} // namespace Models
