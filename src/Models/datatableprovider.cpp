#include "datatableprovider.h"

namespace Models
{

DataTableProvider::DataTableProvider(QObject *parent)
{
}

DataTableProvider::DataTableProvider(std::unique_ptr<QAbstractTableModel> &&model,
                                     StoragedStructures::StructureTypes structureType, QObject *parent)
{
    _tabelModel = std::move(model);
    _structureType = structureType;
}

void DataTableProvider::SetTableModel(std::unique_ptr<QAbstractTableModel> &&model,
                                      StoragedStructures::StructureTypes structureType)
{
    _tabelModel = std::move(model);
    _structureType = structureType;
}

QAbstractTableModel *DataTableProvider::GetTableModel() const
{
    return _tabelModel.get();
}

StoragedStructures::StructureTypes DataTableProvider::GetStructureType() const
{
    return _structureType;
}

} // namespace Models
