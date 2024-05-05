#include "student.h"

namespace Models
{

Student::Student(std::string idStudent, std::string lastName, std::string firstName, std::string idClass,
                 std::string score)
    : _idStudent(idStudent), _lastName(lastName), _firstName(firstName), _idClass(idClass), _score(score)
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
    _idStudent = idStudent;
}

void Student::SetLastName(std::string lastName)
{
    _lastName = lastName;
}

void Student::SetFirstName(std::string firstName)
{
    _firstName = firstName;
}

void Student::SetIdClass(std::string idClass)
{
    _idClass = idClass;
}

void Student::SetScore(std::string score)
{
    _score = score;
}

} // namespace Models
