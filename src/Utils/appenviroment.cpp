#include "appenviroment.h"

namespace Commons
{

std::string AppEnviroment::currentPath()
{
    return QCoreApplication::applicationDirPath().toStdString();
}

const std::string AppEnviroment::_folderData = "DataUser";
const std::string AppEnviroment::_nameFileData = "students.xlsx";

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
    return currentPath() + "/" + _folderData + "/" + _nameFileData;
}
} // namespace Commons
