#ifndef XLSXPROXY_H
#define XLSXPROXY_H

#include "QXlsx/QXlsx/header/xlsxdocument.h"
#include "student.h"
#include <QList>
#include <QObject>
class XLSXProxy
{
  public:
    XLSXProxy() = default;
    QList<Models::Student> ReadData(const QString &dirPath);
    bool CloseDocument();
    bool IsExistedFile(const QString &dirPath);

  private:
    QList<Models::Student> ReadDataFromSheet(QXlsx::Document &sheet);
};

#endif // XLSXPROXY_H
