#ifndef STORAGEDSTRUCTURESELECTIONS_H
#define STORAGEDSTRUCTURESELECTIONS_H

#include <QObject>
#include <QQmlEngine>
namespace Models
{

class StoragedStructures
{
    Q_GADGET
  public:
    StoragedStructures();
    enum StructureTypes
    {
        Vector,
        SList,
        DList,
        CList
    };
    Q_ENUM(StructureTypes);
};

} // namespace Models

#endif // STORAGEDSTRUCTURESELECTIONS_H
