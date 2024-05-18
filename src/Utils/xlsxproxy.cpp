#include "Utils/xlsxproxy.h"
#include "studentvalidator.h"
#include <QFile>
QList<Models::Student> XLSXProxy::ReadData(const QString &dirPath)
{
    try
    {
        if (!IsExistedFile(dirPath))
        {
            return {};
        }

        QXlsx::Document document(dirPath);
        document.selectSheet("Sheet1");

        return ReadDataFromSheet(document);
    }
    catch (const std::exception &e)
    {
        throw;
    }
}

bool XLSXProxy::IsExistedFile(const QString &dirPath)
{
    if (QFile::exists(dirPath))
    {
        return true;
    }
    return false;
}

QList<Models::Student> XLSXProxy::ReadDataFromSheet(QXlsx::Document &sheet)
{
    try
    {
        auto rows = sheet.dimension().lastRow();
        auto cols = sheet.dimension().lastColumn();

        if (rows == 0 || cols == 0)
        {
            return {};
        }

        QList<Models::Student> students(0);

        for (int i = 2; i <= rows; i++)
        {
            Models::Student student;

            for (int j = 2; j <= cols; j++)
            {
                auto cell = sheet.cellAt(i, j);
                auto value = cell->value().toString();

                if (value.isEmpty())
                {
                    continue;
                }
                switch (j)
                {
                case 2:
                    student.SetIdStudent(value);
                    break;
                case 3:
                    student.SetLastName(value);
                    break;
                case 4:
                    student.SetFirstName(value);
                    break;
                case 5:
                    student.SetIdClass(value);
                    break;
                case 6:
                    student.SetScore(value);
                    break;
                default:
                    break;
                }
            }

            if (Commons::StudentValidator::ValidateStudent(student))
            {
                students.append(student);
            }
        }
        return students;
    }
    catch (const std::exception &e)
    {
        throw;
    }
}
