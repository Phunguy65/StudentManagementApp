#ifndef APPENVIROMENT_H
#define APPENVIROMENT_H

#include <QCoreApplication>
#include <string>
namespace Commons
{

class AppEnviroment
{
  public:
    AppEnviroment() = delete;
    static std::string currentPath();

  private:
    static const std::string _currentPath;
    static const std::string _folderData;
    static const std::string _nameFileData;

  public:
    static std::string folderData();
    static std::string nameFileData();
    static std::string pathData();
};

} // namespace Commons

#endif // APPENVIROMENT_H
