#include "vectortablemodel.h"
#include <Utils/comparefunctions.h>
namespace Models
{

VectorTableModel::VectorTableModel(QObject *parent) : QAbstractTableModel(parent)
{
}

int VectorTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _vector.GetSize();
}

int VectorTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 5;
}

QVariant VectorTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        auto student = _vector[index.row()];

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

QVariant VectorTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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

bool VectorTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    auto student = _vector[index.row()];

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

    _vector[index.row()] = student;
    emit dataChanged(index, index, {role});

    return true;
}

Qt::ItemFlags VectorTableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

bool VectorTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);

    for (int i = 0; i < count; ++i)
    {
        _vector.Insert(_vector.GetBegin() + row, Student());
    }

    endInsertRows();

    return true;
}

bool VectorTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);

    for (int i = 0; i < count; ++i)
    {
        _vector.Erase(_vector.GetBegin() + row);
    }

    endRemoveRows();

    return true;
}

void VectorTableModel::dsaSort(int column, SortMethods::SortTypes sortType, Qt::SortOrder order)
{
    emit layoutAboutToBeChanged();
    if (order == Qt::AscendingOrder)
    {
        switch (column)
        {
        case 0: {
            _vector.DSASort((unsigned)sortType, Commons::CompareAsByStudentId());
            break;
        }
        case 1: {
            _vector.DSASort((unsigned)sortType, Commons::CompareAsByStudentLastName());
            break;
        }
        case 2: {
            _vector.DSASort((unsigned)sortType, Commons::CompareAsByStudentFirstName());
            break;
        }
        case 3: {
            _vector.DSASort((unsigned)sortType, Commons::CompareAsByStudentClassId());
            break;
        }
        case 4: {
            _vector.DSASort((unsigned)sortType, Commons::CompareAsByStudentScore());
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
            _vector.DSASort((unsigned)sortType, Commons::CompareDesByStudentId());
            break;
        }
        case 1: {
            _vector.DSASort((unsigned)sortType, Commons::CompareDesByStudentLastName());
            break;
        }
        case 2: {
            _vector.DSASort((unsigned)sortType, Commons::CompareDesByStudentFirstName());
            break;
        }
        case 3: {
            _vector.DSASort((unsigned)sortType, Commons::CompareDesByStudentClassId());
            break;
        }
        case 4: {
            _vector.DSASort((unsigned)sortType, Commons::CompareDesByStudentScore());
            break;
        }
        default:
            break;
        }
    }
    emit layoutChanged();
}

VectorTableModel::~VectorTableModel()
{
    qDebug() << "VectorTableModel destroyed";
}

} // namespace Models
