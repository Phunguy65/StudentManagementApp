#ifndef XLSXPROXY_H
#define XLSXPROXY_H

#include "student.h"
#include <OpenXLSX/OpenXLSX/OpenXLSX.hpp>
#include <QList>
#include <QObject>
class XLSXProxy : public QObject
{
    Q_OBJECT
  public:
    explicit XLSXProxy(QObject *parent = nullptr);

    QList<Models::Student> ReadData(const QString &dirPath);
    bool CloseDocument();

  private:
    OpenXLSX::XLDocument _document;

    bool OpenDocument(const QString &dirPath);
    QList<Models::Student> ReadDataFromSheet(OpenXLSX::XLWorksheet &sheet);
};

#endif // XLSXPROXY_H
