#include "datatableprovider.h"

namespace Models
{

DataTableProvider::DataTableProvider()
{
}

DataTableProvider::DataTableProvider(std::unique_ptr<QAbstractTableModel> &&model,
                                     StorageStructures::StructureTypes structureType)
{
    _tabelModel = std::move(model);
    _structureType = structureType;
}

void DataTableProvider::SetTableModel(std::unique_ptr<QAbstractTableModel> &&model,
                                      StorageStructures::StructureTypes structureType)
{
    _tabelModel = std::move(model);
    _structureType = structureType;
}

QAbstractTableModel *DataTableProvider::GetTableModel() const
{
    return _tabelModel.get();
}
StorageStructures::StructureTypes DataTableProvider::GetStructureType() const
{
    return _structureType;
}

} // namespace Models
