#ifndef XLSXPROXY_H
#define XLSXPROXY_H

#include "student.h"
#include "xlsxdocument.h"
#include <QList>
#include <QObject>
class XLSXProxy
{
  public:
    XLSXProxy() = default;
    QList<Models::Student> ReadData(const QString& dirPath);
    void WriteData(const QString& dirPath, const QList<Models::Student>& students);
    bool IsExistedFile(const QString& dirPath);

  private:
    QList<Models::Student> ReadDataFromSheet(QXlsx::Document& sheet);
    void WriteDataToSheet(QXlsx::Document& sheet, const QList<Models::Student>& students);
};

#endif // XLSXPROXY_H
