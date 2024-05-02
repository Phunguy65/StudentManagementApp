#include "appenviroment.h"

namespace Commons
{

std::string AppEnviroment::currentPath()
{
    return _currentPath;
}

const std::string AppEnviroment::_currentPath = QCoreApplication::applicationDirPath().toStdString();
const std::string AppEnviroment::_folderData = "DataUser";
const std::string AppEnviroment::_nameFileData = "Database.db";

std::string AppEnviroment::folderData()
{
    return _folderData;
}

std::string AppEnviroment::nameFileData()
{
    return _nameFileData;
}

std::string AppEnviroment::pathData()
{
    return _currentPath + "/" + _folderData + "/" + _nameFileData;
}
} // namespace Commons
