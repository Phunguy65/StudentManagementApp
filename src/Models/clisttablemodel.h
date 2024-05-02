#ifndef CLISTTABLEMODEL_H
#define CLISTTABLEMODEL_H

#include "student.h"
#include <CList.hpp>
#include <QAbstractTableModel>
#include <QQmlEngine>
namespace Models
{

class CListTableModel : public QAbstractTableModel
{
  public:
    explicit CListTableModel(QObject *parent = nullptr);

  private:
    DSALibraries::Containers::CList<Student> _clist;
};

} // namespace Models

#endif // CLISTTABLEMODEL_H
