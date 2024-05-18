#ifndef DATATABLEPROVIDER_H
#define DATATABLEPROVIDER_H

#include "qabstractitemmodel.h"
#include "storagedstructureselections.h"
#include <QObject>
namespace Models
{

class DataTableProvider
{
  public:
    explicit DataTableProvider();

    DataTableProvider(std::unique_ptr<QAbstractTableModel> &&model, StorageStructures::StructureTypes structureType);

    void SetTableModel(std::unique_ptr<QAbstractTableModel> &&model, StorageStructures::StructureTypes structureType);

    QAbstractTableModel *GetTableModel() const;

    StorageStructures::StructureTypes GetStructureType() const;

  signals:

  private:
    std::unique_ptr<QAbstractTableModel> _tabelModel;

    StorageStructures::StructureTypes _structureType;
};

} // namespace Models

#endif // DATATABLEPROVIDER_H
