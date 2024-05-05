#include "overviewcontroller.h"
#include "clisttablemodel.h"
#include "datatableprovider.h"
#include "dlisttablemodel.h"
#include "slisttablemodel.h"
#include "sortfiltertablemodel.h"
#include "storagedstructureselections.h"
#include "vectortablemodel.h"
#include <Utils/studentvalidator.h>

namespace Models
{

OverviewController::OverviewController(QObject *parent)
{
    _currentDataProvider = std::make_unique<DataTableProvider>(this);
    _sortFilterModel = std::make_unique<SortFilterTableModel>(this);

    _currentDataProvider->SetTableModel(std::make_unique<VectorTableModel>(this),
                                        StoragedStructures::StructureTypes::Vector);
    _sortFilterModel->setSourceModel(_currentDataProvider->GetTableModel());
}

int OverviewController::RowCount() const
{
    return _currentDataProvider->GetTableModel()->rowCount();
}

void OverviewController::setStructureType(StoragedStructures::StructureTypes structureType)
{
    if (_currentDataProvider->GetStructureType() == structureType)
    {
        return;
    }
    try
    {
        this->SetStructureTypeInternal(structureType);
        emit rowCountChanged();
    }
    catch (const std::invalid_argument &e)
    {
        emit errorOccured(e.what());
    }
    catch (...)
    {
        emit errorOccured("Unknown error occured");
    }
}

void OverviewController::addStudent(const QString &idStudent, const QString &lastName, const QString &firstName,
                                    const QString &idClass, const QString &score)
{
    Student studentData(idStudent.toStdString(), lastName.toStdString(), firstName.toStdString(), idClass.toStdString(),
                        score.toStdString());
    try
    {
        ValidateStudentData(studentData);
        if (IsUniqueStudent(studentData))
        {
            AddStudentInternal(studentData);
        }
        else
        {
            emit errorOccured("Student already exists");
        }
    }
    catch (const std::invalid_argument &e)
    {
        emit errorOccured(e.what());
    }
    catch (...)
    {
        emit errorOccured("Unknown error occured");
    }
}
void OverviewController::removeStudent(int index)
{
}

void OverviewController::updateStudent(int index, const QString &name, const QString &surname, const QString &group,
                                       const QString &score)
{
}

void OverviewController::ValidateStudentData(const Student &studentData)
{
    if (!Commons::StudentValidator::ValidateStudentId(QString::fromStdString(studentData.GetIdStudent())))
    {
        throw std::invalid_argument("Invalid student id");
    }
    if (!Commons::StudentValidator::ValidateStudentFirstName(QString::fromStdString(studentData.GetFirstName())))
    {
        throw std::invalid_argument("Invalid student first name");
    }
    if (!Commons::StudentValidator::ValidateStudentLastName(QString::fromStdString(studentData.GetLastName())))
    {
        throw std::invalid_argument("Invalid student last name");
    }
    if (!Commons::StudentValidator::ValidateStudentIdClass(QString::fromStdString(studentData.GetIdClass())))
    {
        throw std::invalid_argument("Invalid student id class");
    }
    if (!Commons::StudentValidator::ValidateStudentScore(QString::fromStdString(studentData.GetScore())))
    {
        throw std::invalid_argument("Invalid student score");
    }
}

void OverviewController::SetStructureTypeInternal(StoragedStructures::StructureTypes structureType)
{
    switch (structureType)
    {
    case StoragedStructures::StructureTypes::Vector: {
        auto newModel = std::make_unique<VectorTableModel>(this);
        LetMoveDataToNewModel(_currentDataProvider->GetTableModel(),
                              qobject_cast<QAbstractTableModel *>(newModel.get()));
        _currentDataProvider->SetTableModel(std::move(newModel), structureType);
        _sortFilterModel->setSourceModel(_currentDataProvider->GetTableModel());
        break;
    }
    case StoragedStructures::StructureTypes::SList: {
        auto newModel = std::make_unique<SListTableModel>(this);
        LetMoveDataToNewModel(_currentDataProvider->GetTableModel(),
                              qobject_cast<QAbstractTableModel *>(newModel.get()));
        _currentDataProvider->SetTableModel(std::move(newModel), structureType);
        _sortFilterModel->setSourceModel(_currentDataProvider->GetTableModel());
        break;
    }
    case StoragedStructures::StructureTypes::DList: {
        auto newModel = std::make_unique<DListTableModel>(this);
        LetMoveDataToNewModel(_currentDataProvider->GetTableModel(),
                              qobject_cast<QAbstractTableModel *>(newModel.get()));
        _currentDataProvider->SetTableModel(std::move(newModel), structureType);
        _sortFilterModel->setSourceModel(_currentDataProvider->GetTableModel());
        break;
    }

    case StoragedStructures::StructureTypes::CList: {
        auto newModel = std::make_unique<CListTableModel>(this);
        LetMoveDataToNewModel(_currentDataProvider->GetTableModel(),
                              qobject_cast<QAbstractTableModel *>(newModel.get()));
        _currentDataProvider->SetTableModel(std::move(newModel), structureType);
        _sortFilterModel->setSourceModel(_currentDataProvider->GetTableModel());
        break;
    }
    default:
        throw std::invalid_argument("Unknown structure type");
        break;
    }
}

void OverviewController::LetMoveDataToNewModel(QAbstractTableModel *oldModel, QAbstractTableModel *newModel)
{
    auto currentRow = oldModel->rowCount();
    auto currentColumn = oldModel->columnCount();
    for (int i = 0; i < currentRow; ++i)
    {
        newModel->insertRow(i);
        for (int j = 0; j < currentColumn; ++j)
        {
            auto data = oldModel->index(i, j);
            newModel->setData(data, oldModel->data(data));
        }
    }
}

void OverviewController::AddStudentInternal(const Student &studentData)
{
    if (this->_currentDataProvider->GetStructureType() != StoragedStructures::StructureTypes::Vector)
    {
        _currentDataProvider->GetTableModel()->insertRow(0);

        emit rowCountChanged();
    }
    emit rowCountChanged();
}

} // namespace Models
