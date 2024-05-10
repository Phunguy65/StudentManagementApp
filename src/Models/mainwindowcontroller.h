#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QObject>
#include <QQmlEngine>
#include <Utils/xlsxproxy.h>
namespace Models
{

class MainWindowController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
  public:
    explicit MainWindowController(QObject *parent = nullptr);

  signals:

    void beginReadData();
    void endReadData();
    void dataReadError(const QString &errorMessage);
    void dataRead(const QList<Models::Student> &students);

  public slots:

    void openFile(const QString &dirPath);

  private:
    std::unique_ptr<XLSXProxy> _xlsxProxy;

    void ReadDataInternal(const QString &dirPath);
};

} // namespace Models

#endif // MAINWINDOWCONTROLLER_H
