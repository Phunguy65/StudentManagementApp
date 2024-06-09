#include "comparefunctions.h"
#include <QCollator>
#include <QLocale>
namespace Commons
{

bool CompareAsByStudentId::operator()(const Models::Student& first, const Models::Student& second) const
{
    return first.GetIdStudent() < second.GetIdStudent();
}
bool CompareAsByStudentLastName::operator()(const Models::Student& first, const Models::Student& second) const
{
    if (first.GetLastName() == second.GetLastName())
        return CompareAsByStudentId()(first, second);

    QCollator collator;

    collator.setLocale(QLocale(QLocale::Language::Vietnamese, QLocale::Country::Vietnam));

    return collator.compare(first.GetLastName(), second.GetLastName()) < 0;
}
bool CompareAsByStudentFirstName::operator()(const Models::Student& first, const Models::Student& second) const
{
    if (first.GetFirstName() == second.GetFirstName())
        return CompareAsByStudentId()(first, second);

    QCollator collator;

    collator.setLocale(QLocale(QLocale::Language::Vietnamese, QLocale::Country::Vietnam));

    return collator.compare(first.GetFirstName(), second.GetFirstName()) < 0;
}
bool CompareAsByStudentClassId::operator()(const Models::Student& first, const Models::Student& second) const
{
    if (first.GetIdClass() == second.GetIdClass())
        return CompareAsByStudentId()(first, second);

    return first.GetIdClass() < second.GetIdClass();
}
bool CompareAsByStudentScore::operator()(const Models::Student& first, const Models::Student& second) const
{
    auto const firstScore = first.GetScore().toInt();
    auto const secondScore = second.GetScore().toInt();

    if (firstScore == secondScore)
        return CompareAsByStudentId()(first, second);

    return firstScore < secondScore;
}
bool CompareDesByStudentId::operator()(const Models::Student& first, const Models::Student& second) const
{
    return first.GetIdStudent() > second.GetIdStudent();
}
bool CompareDesByStudentLastName::operator()(const Models::Student& first, const Models::Student& second) const
{
    if (first.GetLastName() == second.GetLastName())
        return CompareDesByStudentId()(first, second);

    QCollator collator;

    collator.setLocale(QLocale(QLocale::Language::Vietnamese, QLocale::Country::Vietnam));

    return collator.compare(first.GetLastName(), second.GetLastName()) > 0;
}
bool CompareDesByStudentFirstName::operator()(const Models::Student& first, const Models::Student& second) const
{
    if (first.GetFirstName() == second.GetFirstName())
        return CompareDesByStudentId()(first, second);

    QCollator collator;

    collator.setLocale(QLocale(QLocale::Language::Vietnamese, QLocale::Country::Vietnam));

    return collator.compare(first.GetFirstName(), second.GetFirstName()) > 0;
}
bool CompareDesByStudentClassId::operator()(const Models::Student& first, const Models::Student& second) const
{
    if (first.GetIdClass() == second.GetIdClass())
        return CompareDesByStudentId()(first, second);

    return first.GetIdClass() > second.GetIdClass();
}
bool CompareDesByStudentScore::operator()(const Models::Student& first, const Models::Student& second) const
{
    auto const firstScore = first.GetScore().toInt();
    auto const secondScore = second.GetScore().toInt();

    if (firstScore == secondScore)
        return CompareDesByStudentId()(first, second);

    return firstScore > secondScore;
}
} // namespace Commons
