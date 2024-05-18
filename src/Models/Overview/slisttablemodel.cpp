#include "slisttablemodel.h"
#include "comparefunctions.h"

namespace Models
{

SListTableModel::SListTableModel(QObject *parent) : QAbstractTableModel{parent}
{
    _slist = DSALibraries::Containers::SList<Student>();
}

int SListTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _slist.GetSize();
}

int SListTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 5;
}

QVariant SListTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        auto it = _slist.GetConstBegin();
        auto idx = index.row();

        while (idx-- > 0 && it.PointerNext() != _slist.GetConstEnd())
        {
            ++it;
        }

        if (it == _slist.GetConstEnd())
            return QVariant();

        auto &student = *it;

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

QVariant SListTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return tr("ID Student");
        case 1:
            return tr("Last Name");
        case 2:
            return tr("First Name");
        case 3:
            return tr("ID Class");
        case 4:
            return tr("Score");
        default:
            return QVariant();
        }
    }

    return QVariant();
}

bool SListTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    auto it = _slist.GetBegin();
    auto idx = index.row();

    while (idx-- > 0 && it.PointerNext() != _slist.GetEnd())
    {
        ++it;
    }

    if (it == _slist.GetEnd())
        return false;

    auto &student = *it;

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

Qt::ItemFlags SListTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

bool SListTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);

    auto it = _slist.GetBeginFromHead();
    auto idx = row;

    while (idx-- > 0)
    {
        if (it.PointerNext() == _slist.GetEnd())
        {
            break;
        }
        ++it;
    }

    while (count-- > 0)
    {
        it = _slist.InsertAfter(it, Student());
    }

    endInsertRows();
    return true;
}

bool SListTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);

    auto it = _slist.GetConstBeginFromHead();
    auto idx = row;

    while (idx-- > 0)
    {
        if (it.PointerNext() == _slist.GetEnd())
        {
            break;
        }
        ++it;
    }

    while (count-- > 0)
    {
        if (it == _slist.GetEnd())
        {
            break;
        }
        it = _slist.EraseAfter(it);
    }

    endRemoveRows();
    return true;
}

void SListTableModel::dsaSort(int column, SortMethods::SortTypes sortType, Qt::SortOrder order)
{
    if (order == Qt::AscendingOrder)
    {
        switch (column)
        {
        case 0: {
            _slist.DSASort((unsigned)sortType, Commons::CompareAsByStudentId());
            break;
        }
        case 1: {
            _slist.DSASort((unsigned)sortType, Commons::CompareAsByStudentLastName());
            break;
        }
        case 2: {
            _slist.DSASort((unsigned)sortType, Commons::CompareAsByStudentFirstName());
            break;
        }
        case 3: {
            _slist.DSASort((unsigned)sortType, Commons::CompareAsByStudentClassId());
            break;
        }
        case 4: {
            _slist.DSASort((unsigned)sortType, Commons::CompareAsByStudentScore());
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
            _slist.DSASort((unsigned)sortType, Commons::CompareDesByStudentId());
            break;
        }
        case 1: {
            _slist.DSASort((unsigned)sortType, Commons::CompareDesByStudentLastName());
            break;
        }
        case 2: {
            _slist.DSASort((unsigned)sortType, Commons::CompareDesByStudentFirstName());
            break;
        }
        case 3: {
            _slist.DSASort((unsigned)sortType, Commons::CompareDesByStudentClassId());
            break;
        }
        case 4: {
            _slist.DSASort((unsigned)sortType, Commons::CompareDesByStudentScore());
            break;
        }
        default:
            break;
        }
    }
    emit layoutChanged();
}

SListTableModel::~SListTableModel()
{
    qDebug() << "SListTableModel destroyed";
}

} // namespace Models
