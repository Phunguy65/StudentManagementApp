#ifndef FILTERCOLUMNSELECTIONS_H
#define FILTERCOLUMNSELECTIONS_H
#include <QQmlEngine>
namespace Models
{

class FilterColumnSelections
{
    Q_GADGET
  public:
    FilterColumnSelections();

    enum FilterColumn
    {
        IdStudent,
        LastName,
        FirstName,
        IdClass,
        Score
    };

    Q_ENUM(FilterColumn);
};

} // namespace Models

#endif // FILTERCOLUMNSELECTIONS_H
