#include "student.h"

namespace Models
{

Student::Student(std::string idStudent, std::string lastName, std::string firstName, std::string idClass,
                 std::string score)
    : _idStudent(idStudent), _lastName(lastName), _firstName(firstName), _idClass(idClass), _score(score)
{
}

std::string Student::getIdStudent()
{
    return _idStudent;
}

std::string Student::getLastName()
{
    return _lastName;
}

std::string Student::getFirstName()
{
    return _firstName;
}

std::string Student::getIdClass()
{
    return _idClass;
}

std::string Student::getScore()
{
    return _score;
}

void Student::setIdStudent(std::string idStudent)
{
    _idStudent = idStudent;
}

void Student::setLastName(std::string lastName)
{
    _lastName = lastName;
}

void Student::setFirstName(std::string firstName)
{
    _firstName = firstName;
}

void Student::setIdClass(std::string idClass)
{
    _idClass = idClass;
}

void Student::setScore(std::string score)
{
    _score = score;
}

} // namespace Models
