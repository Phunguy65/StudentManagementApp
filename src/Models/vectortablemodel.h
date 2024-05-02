#ifndef VECTORTABLEMODEL_H
#define VECTORTABLEMODEL_H

#include "student.h"
#include <QAbstractTableModel>
#include <QQmlEngine>
#include <Vector/Vector.hpp>
namespace Models
{

class VectorTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
  public:
    explicit VectorTableModel(QObject *parent = nullptr);

  private:
    DSALibraries::Containers::Vector<Student> _vector;
};

} // namespace Models

#endif // VECTORTABLEMODEL_H
