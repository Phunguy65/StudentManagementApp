#ifndef STUDENT_H
#define STUDENT_H

#include <string>
namespace Models
{

class Student
{
  private:
    std::string _idStudent;
    std::string _lastName;
    std::string _firstName;
    std::string _idClass;
    std::string _score;

  public:
    Student() = default;
    Student(std::string idStudent, std::string lastName, std::string firstName, std::string idClass, std::string score);
    ~Student() = default;
    std::string GetIdStudent() const;
    std::string GetLastName() const;
    std::string GetFirstName() const;
    std::string GetIdClass() const;
    std::string GetScore() const;
    void SetIdStudent(std::string idStudent);
    void SetLastName(std::string lastName);
    void SetFirstName(std::string firstName);
    void SetIdClass(std::string idClass);
    void SetScore(std::string score);
};

} // namespace Models

#endif // STUDENT_H
