#include "mainwindowcontroller.h"
#include "appenviroment.h"
#include <QDir>
#include <QFile>
#include <QFileInfo>
namespace Models
{

void MainWindowController::openFile(const QUrl& dirPath)
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

void MainWindowController::ReadDataInternal(const QString& dirPath)
{
    try
    {
        auto students = _xlsxProxy.ReadData(dirPath);
        emit dataRead(students);
    }
    catch (const std::exception& e)
    {
        emit dataReadError(e.what());
    }
}

void MainWindowController::saveFile(const QUrl& dirPath, const QList<Student>& students)
{
    emit beginWriteData();
    WriteDataInternal(dirPath.toLocalFile(), students);
    emit endWriteData();
}

void MainWindowController::WriteDataInternal(const QString& dirPath, const QList<Student>& students)
{
    try
    {
        _xlsxProxy.WriteData(dirPath, students);
    }
    catch (const std::exception& e)
    {
        emit dataReadError(e.what());
    }
}

void MainWindowController::init()
{
    auto dataFilePath = QString::fromStdString(Commons::AppEnviroment::pathData());

    QDir dirPath{Commons::AppEnviroment::currentPath().c_str()};
    QFileInfo file{dataFilePath};

    if (!dirPath.exists(Commons::AppEnviroment::folderData().c_str()))
    {
        dirPath.mkdir(Commons::AppEnviroment::folderData().c_str());
    }
    else
    {
        if (file.exists())
        {
            emit beginReadData();
            this->openFile(QUrl::fromLocalFile(file.filePath()));
            emit endReadData();
        }
    }
}
MainWindowController::MainWindowController(QObject* parent) : QObject(parent)
{
}
} // namespace Models
