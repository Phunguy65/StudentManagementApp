#include "mainwindowcontroller.h"
#include <QFile>
namespace Models
{

void MainWindowController::openFile(const QUrl &dirPath)
{
    QFile file{dirPath.toLocalFile()};

    if (!file.exists())
    {
        emit dataReadError("File does not exist");
        return;
    }

    emit beginReadData();
    ReadDataInternal(dirPath.toLocalFile());
    emit endReadData();
}

void MainWindowController::ReadDataInternal(const QString &dirPath)
{
    try
    {
        auto students = _xlsxProxy.ReadData(dirPath);
        emit dataRead(students);
    }
    catch (const std::exception &e)
    {
        emit dataReadError(e.what());
    }
}

MainWindowController::MainWindowController(QObject *parent) : QObject(parent)
{
    _xlsxProxy = XLSXProxy();
}
} // namespace Models
