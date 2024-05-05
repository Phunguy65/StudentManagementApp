#ifndef DATATABLEPROVIDER_H
#define DATATABLEPROVIDER_H

#include "qabstractitemmodel.h"
#include "storagedstructureselections.h"
#include <QObject>
namespace Models
{

class DataTableProvider : public QObject
{
    Q_OBJECT
  public:
    explicit DataTableProvider(QObject *parent = nullptr);

    DataTableProvider(std::unique_ptr<QAbstractTableModel> &&model, StoragedStructures::StructureTypes structureType,
                      QObject *parent = nullptr);

    void SetTableModel(std::unique_ptr<QAbstractTableModel> &&model, StoragedStructures::StructureTypes structureType);

    QAbstractTableModel *GetTableModel() const;

    StoragedStructures::StructureTypes GetStructureType() const;

  signals:

  private:
    std::unique_ptr<QAbstractTableModel> _tabelModel;

    StoragedStructures::StructureTypes _structureType;
};

} // namespace Models

#endif // DATATABLEPROVIDER_H
