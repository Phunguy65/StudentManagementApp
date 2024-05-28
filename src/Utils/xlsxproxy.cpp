#include "xlsxproxy.h"
#include "studentvalidator.h"
#include <QFile>
#include <QtGui/QColor>
QList<Models::Student> XLSXProxy::ReadData(const QString& dirPath)
{
    try
    {
        if (!IsExistedFile(dirPath))
        {
            return {};
        }

        QXlsx::Document document(dirPath);

        if (!document.isLoadPackage())
        {
            throw std::runtime_error("Cannot load file");
        }

        if (!document.sheetNames().contains("Sheet1"))
        {
            return {};
        }

        document.selectSheet("Sheet1");
        return ReadDataFromSheet(document);
    }
    catch (const std::exception& e)
    {
        throw;
    }
}

bool XLSXProxy::IsExistedFile(const QString& dirPath)
{
    if (QFile::exists(dirPath))
    {
        return true;
    }
    return false;
}

QList<Models::Student> XLSXProxy::ReadDataFromSheet(QXlsx::Document& sheet)
{
    try
    {
        auto rows = sheet.dimension().lastRow();
        auto cols = sheet.dimension().lastColumn();

        if (rows == 0 || (cols >= 7 && cols <= 1))
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
    catch (const std::exception& e)
    {
        throw;
    }
}

void XLSXProxy::WriteData(const QString& dirPath, const QList<Models::Student>& students)
{
    try
    {
        QXlsx::Document document;
        WriteDataToSheet(document, students);
        document.saveAs(dirPath);
    }
    catch (const std::exception& e)
    {
        throw;
    }
}

void XLSXProxy::WriteDataToSheet(QXlsx::Document& sheet, const QList<Models::Student>& students)
{
    try
    {
        QXlsx::Format format;
        format.setFontBold(true);
        format.setFontSize(12);
        format.setBorderStyle(QXlsx::Format::BorderStyle::BorderThin);
        format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        format.setVerticalAlignment(QXlsx::Format::AlignVCenter);
        format.setPatternBackgroundColor(QColor(Qt::green));

        sheet.write("A1", "Order", format);
        sheet.write("B1", "Id Student", format);
        sheet.write("C1", "Last Name", format);
        sheet.write("D1", "First Name", format);
        sheet.write("E1", "Id Class", format);
        sheet.write("F1", "Score", format);

        sheet.setColumnWidth(1, 10);
        sheet.setColumnWidth(2, 30);
        sheet.setColumnWidth(3, 30);
        sheet.setColumnWidth(4, 30);
        sheet.setColumnWidth(5, 30);
        sheet.setColumnWidth(6, 10);

        for (int i = 0; i < students.size(); i++)
        {
            auto student = students[i];
            sheet.write(i + 2, 1, i + 1);
            sheet.write(i + 2, 2, student.GetIdStudent());
            sheet.write(i + 2, 3, student.GetLastName());
            sheet.write(i + 2, 4, student.GetFirstName());
            sheet.write(i + 2, 5, student.GetIdClass());
            sheet.write(i + 2, 6, student.GetScore());
        }
    }
    catch (const std::exception& e)
    {
        throw;
    }
}
