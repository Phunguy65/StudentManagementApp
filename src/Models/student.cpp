#include "student.h"
#include <QString>
namespace Models
{

Student::Student(std::string idStudent, std::string lastName, std::string firstName, std::string idClass,
                 std::string score)
    : _idStudent(this->UpperlizeString(idStudent)), _lastName(this->UpperlizeString(lastName)),
      _firstName(this->UpperlizeString(firstName)), _idClass(this->UpperlizeString(idClass)),
      _score(this->UpperlizeString(score))
{
}

std::string Student::GetIdStudent() const
{
    return _idStudent;
}

std::string Student::GetLastName() const
{
    return _lastName;
}

std::string Student::GetFirstName() const
{
    return _firstName;
}

std::string Student::GetFullName() const
{
    return _lastName + " " + _firstName;
}

std::string Student::GetIdClass() const
{
    return _idClass;
}

std::string Student::GetScore() const
{
    return _score;
}

void Student::SetIdStudent(std::string idStudent)
{
    _idStudent = this->UpperlizeString(idStudent);
}

void Student::SetLastName(std::string lastName)
{
    _lastName = this->UpperlizeString(lastName);
}

void Student::SetFirstName(std::string firstName)
{
    _firstName = this->UpperlizeString(firstName);
}

void Student::SetIdClass(std::string idClass)
{
    _idClass = this->UpperlizeString(idClass);
}

void Student::SetScore(std::string score)
{
    _score = score;
}

std::string Student::UpperlizeString(const std::string &str)
{
    if (str.empty())
    {
        return str;
    }

    QString result = QString::fromStdString(str);
    return result.toUpper().toStdString();
}

} // namespace Models
