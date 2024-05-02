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
    std::string getIdStudent();
    std::string getLastName();
    std::string getFirstName();
    std::string getIdClass();
    std::string getScore();
    void setIdStudent(std::string idStudent);
    void setLastName(std::string lastName);
    void setFirstName(std::string firstName);
    void setIdClass(std::string idClass);
    void setScore(std::string score);
};

} // namespace Models

#endif // STUDENT_H
