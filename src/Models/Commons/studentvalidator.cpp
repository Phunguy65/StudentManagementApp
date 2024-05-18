#include "studentvalidator.h"

namespace Commons
{
StudentValidator::StudentValidator()
{
}

bool StudentValidator::ValidateStudentId(const QString &studentId)
{
    return std::regex_match(studentId.toStdString(), RegularExpressionStudentId);
}

bool StudentValidator::ValidateStudentLastName(const QString &studentName)
{
    return std::regex_match(studentName.toStdString(), RegularExpressionStudentName);
}

bool StudentValidator::ValidateStudentFirstName(const QString &studentName)
{
    return std::regex_match(studentName.toStdString(), RegularExpressionStudentName);
}

bool StudentValidator::ValidateStudentIdClass(const QString &studentClass)
{
    return std::regex_match(studentClass.toStdString(), RegularExpressionStudentClass);
}

bool StudentValidator::ValidateStudentScore(const QString &studentScore)
{
    return std::regex_match(studentScore.toStdString(), RegularExpressionStudentScore);
}

bool StudentValidator::ValidateStudent(const Models::Student &student)
{
    return ValidateStudentId(student.GetIdStudent()) && ValidateStudentLastName(student.GetLastName()) &&
           ValidateStudentFirstName(student.GetFirstName()) && ValidateStudentIdClass(student.GetIdClass()) &&
           ValidateStudentScore(student.GetScore());
}

const std::regex StudentValidator::RegularExpressionStudentId = std::regex("^(n|N)\\d{2}[c-dC-D]{2}[a-zA-Z]{2}\\d{3}$");

const std::regex StudentValidator::RegularExpressionStudentName =
    std::regex("^[a-zA-Z_ÀÁÂÃÈÉÊÌÍÒÓÔÕÙÚĂĐĨŨƠàáâãèéêìíòóôõùúăđĩũơƯĂẠẢẤẦẨẪẬẮẰẲẴẶ+"
               "ẸẺẼỀỀỂưăạảấầẩẫậắằẳẵặẹẻẽềềểỄỆỈỊỌỎỐỒỔỖỘỚỜỞỠỢỤỦỨỪễệỉịọỏốồổỗộớờởỡợ+ụủứừỬỮỰỲỴÝỶỸửữựỳỵỷỹ\\s]+$");

const std::regex StudentValidator::RegularExpressionStudentClass = std::regex("^(d|D)\\d{2}[a-zA-Z]{1,6}\\d{2}-(n|N)$");
const std::regex StudentValidator::RegularExpressionStudentScore = std::regex("^(\\d|10)$");
} // namespace Commons
