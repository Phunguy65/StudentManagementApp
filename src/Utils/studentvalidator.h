#ifndef STUDENTVALIDATOR_H
#define STUDENTVALIDATOR_H

#include "student.h"
#include <QString>
#include <regex>
namespace Commons
{
class StudentValidator
{
  public:
    StudentValidator();

    static bool ValidateStudentId(const QString &studentId);
    static bool ValidateStudentLastName(const QString &studentName);
    static bool ValidateStudentFirstName(const QString &studentName);
    static bool ValidateStudentIdClass(const QString &studentClass);
    static bool ValidateStudentScore(const QString &studentScore);
    static bool ValidateStudent(const Models::Student &student);

    static const std::regex RegularExpressionStudentId;
    static const std::regex RegularExpressionStudentName;
    static const std::regex RegularExpressionStudentClass;
    static const std::regex RegularExpressionStudentScore;
};
} // namespace Commons
#endif // STUDENTVALIDATOR_H
