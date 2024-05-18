#include "student.h"
#include <QString>
namespace Models
{

Student::Student(QString idStudent, QString lastName, QString firstName, QString idClass, QString score)
    : _idStudent(this->UpperlizeString(idStudent)), _lastName(this->UpperlizeString(lastName)),
      _firstName(this->UpperlizeString(firstName)), _idClass(this->UpperlizeString(idClass)),
      _score(this->UpperlizeString(score))
{
}

QString Student::GetIdStudent() const
{
    return _idStudent;
}

QString Student::GetLastName() const
{
    return _lastName;
}

QString Student::GetFirstName() const
{
    return _firstName;
}

QString Student::GetFullName() const
{
    return _lastName + " " + _firstName;
}

QString Student::GetIdClass() const
{
    return _idClass;
}

QString Student::GetScore() const
{
    return _score;
}

void Student::SetIdStudent(QString idStudent)
{
    _idStudent = this->UpperlizeString(idStudent);
}

void Student::SetLastName(QString lastName)
{
    _lastName = this->UpperlizeString(lastName);
}

void Student::SetFirstName(QString firstName)
{
    _firstName = this->UpperlizeString(firstName);
}

void Student::SetIdClass(QString idClass)
{
    _idClass = this->UpperlizeString(idClass);
}

void Student::SetScore(QString score)
{
    _score = score;
}

bool Student::operator<(const Student &other) const
{
    if (_lastName == other._lastName || _idClass == other._idClass || _score == other._score ||
        _firstName == other._firstName)
    {
        return _idStudent < other._idStudent;
    }

    return _idStudent < other._idStudent;
}

QString Student::UpperlizeString(const QString &str)
{
    if (str.isEmpty())
    {
        return str;
    }

    return str.toUpper();
}

} // namespace Models
