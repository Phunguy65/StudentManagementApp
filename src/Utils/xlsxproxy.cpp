#include "xlsxproxy.h"
#include "Utils/studentvalidator.h"

QList<Models::Student> XLSXProxy::ReadData(const QString &dirPath)
{
    try
    {
        if (!OpenDocument(dirPath))
        {
            return {};
        }

        auto sheet = _document.workbook().worksheet("Sheet1");

        if (!sheet.isActive())
        {
            sheet.setActive();
        }

        return ReadDataFromSheet(sheet);
    }
    catch (const std::exception &e)
    {
        throw;
    }
}

bool XLSXProxy::OpenDocument(const QString &dirPath)
{
    try
    {
        _document.open(dirPath.toStdString());
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return true;
}

bool XLSXProxy::CloseDocument()
{
    if (!_document.isOpen())
    {
        return false;
    }

    _document.close();
    return true;
}

QList<Models::Student> XLSXProxy::ReadDataFromSheet(OpenXLSX::XLWorksheet &sheet)
{
    try
    {
        auto rows = sheet.rowCount();
        auto cols = sheet.columnCount();

        if (rows == 0 || cols == 0)
        {
            return {};
        }

        QList<Models::Student> students;

        for (int i = 1; i <= rows; i++)
        {
            Models::Student student;

            for (int j = 1; j <= cols; j++)
            {
                auto cell = sheet.cell(i, j);
                auto value = cell.value().get<std::string>();

                if (value.empty())
                {
                    continue;
                }
                switch (j)
                {
                case 1:
                    student.SetIdStudent(value);
                    break;
                case 2:
                    student.SetLastName(value);
                    break;
                case 3:
                    student.SetFirstName(value);
                    break;
                case 4:
                    student.SetIdClass(value);
                    break;
                case 5:
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
XLSXProxy::XLSXProxy(QObject *parent) : QObject(parent)
{
    _document = OpenXLSX::XLDocument();
}
