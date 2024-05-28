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
    explicit MainWindowController(QObject* parent = nullptr);

  signals:

    void beginReadData();
    void endReadData();
    void beginWriteData();
    void endWriteData();
    void dataReadError(const QString& errorMessage);
    void dataRead(const QList<Models::Student>& students);

    void initialized(const QList<Models::Student>& students);
  public slots:

    void openFile(const QUrl& dirPath);
    void saveFile(const QUrl& dirPath, const QList<Models::Student>& students);

    void init();

  private:
    XLSXProxy _xlsxProxy;

    void ReadDataInternal(const QString& dirPath);
    void WriteDataInternal(const QString& dirPath, const QList<Models::Student>& students);
};

} // namespace Models

#endif // MAINWINDOWCONTROLLER_H
