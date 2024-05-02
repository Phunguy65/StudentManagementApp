#ifndef DLISTTABLEMODEL_H
#define DLISTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QQmlEngine>

namespace Models
{

class DListTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
  public:
    explicit DListTableModel(QObject *parent = nullptr);
};

} // namespace Models

#endif // DLISTTABLEMODEL_H
