#ifndef OVERVIEWCONTROLLER_H
#define OVERVIEWCONTROLLER_H

#include "datatableprovider.h"
#include "sortfiltertablemodel.h"
#include "storagedstructureselections.h"
#include "student.h"
#include <QObject>
#include <QQmlApplicationEngine>
namespace Models
{

class OverviewController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int rowCount READ RowCount NOTIFY rowCountChanged)
  public:
    explicit OverviewController(QObject *parent = nullptr);

    int RowCount() const;
  signals:

    void dataProviderChanged();
    void rowCountChanged();

  public slots:

    void setStructureType(StoragedStructures::StructureTypes structureType);
    void addStudent(const QString &idStudent, const QString &lastName, const QString &firstName, const QString &idClass,
                    const QString &score);
    void removeStudent(int index);
    void updateStudent(int index, const QString &name, const QString &surname, const QString &group,
                       const QString &score);

    void errorOccured(const QString &error);

  private:
    std::unique_ptr<DataTableProvider> _currentDataProvider;
    std::unique_ptr<SortFilterTableModel> _sortFilterModel;

    bool IsUniqueStudent(const Student &studentData);
    void ValidateStudentData(const Student &studentData);
    void SetStructureTypeInternal(StoragedStructures::StructureTypes structureType);
    void LetMoveDataToNewModel(QAbstractTableModel *oldModel, QAbstractTableModel *newModel);

    void AddStudentInternal(const Student &studentData);
};

} // namespace Models

#endif // OVERVIEWCONTROLLER_H
