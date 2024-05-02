#include "vectortablemodel.h"

namespace Models
{

VectorTableModel::VectorTableModel(QObject *parent) : QAbstractTableModel{parent}
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
            return QString::fromStdString(student.getIdStudent());
        case 1:
            return QString::fromStdString(student.getLastName());
        case 2:
            return QString::fromStdString(student.getFirstName());
        case 3:
            return QString::fromStdString(student.getIdClass());
        case 4:
            return QString::fromStdString(student.getScore());
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
        student.setIdStudent(value.toString().toStdString());
        break;
    case 1:
        student.setLastName(value.toString().toStdString());
        break;
    case 2:
        student.setFirstName(value.toString().toStdString());
        break;
    case 3:
        student.setIdClass(value.toString().toStdString());
        break;
    case 4:
        student.setScore(value.toString().toStdString());
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

} // namespace Models
