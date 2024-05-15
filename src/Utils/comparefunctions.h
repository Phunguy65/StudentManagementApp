#ifndef COMPAREFUNCTIONS_H
#define COMPAREFUNCTIONS_H

#include "student.h"
namespace Commons
{

/*Compare functions for sorting students ascendingly*/
struct CompareAsByStudentId
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

struct CompareAsByStudentLastName
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

struct CompareAsByStudentFirstName
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

struct CompareAsByStudentClassId
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

struct CompareAsByStudentScore
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

/*Compare functions for sorting students descendingly*/

struct CompareDesByStudentId
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

struct CompareDesByStudentLastName
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

struct CompareDesByStudentFirstName
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

struct CompareDesByStudentClassId
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

struct CompareDesByStudentScore
{
    bool operator()(const Models::Student &first, const Models::Student &second) const;
};

} // namespace Commons

#endif // COMPAREFUNCTIONS_H
