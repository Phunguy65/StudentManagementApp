#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <string>
namespace Models
{

class Student
{
  private:
    QString _idStudent;
    QString _lastName;
    QString _firstName;
    QString _idClass;
    QString _score;

    QString UpperlizeString(const QString &str);

  public:
    Student() = default;
    Student(QString idStudent, QString lastName, QString firstName, QString idClass, QString score);

    QString GetIdStudent() const;
    QString GetLastName() const;
    QString GetFirstName() const;
    QString GetFullName() const;
    QString GetIdClass() const;
    QString GetScore() const;

    void SetIdStudent(QString idStudent);
    void SetLastName(QString lastName);
    void SetFirstName(QString firstName);
    void SetIdClass(QString idClass);
    void SetScore(QString score);

    bool operator<(const Student &other) const;
};

} // namespace Models

#endif // STUDENT_H
