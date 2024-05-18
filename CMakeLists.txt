cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(StudentManagementApp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.7 REQUIRED COMPONENTS Core Gui Qml Quick Widgets)


if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

qt_add_executable(StudentManagementApp src/main.cpp

    src/Models/Commons/student.h src/Models/Commons/student.cpp
    src/Models/Commons/studentvalidator.h src/Models/Commons/studentvalidator.cpp
    src/Models/Commons/comparefunctions.cpp src/Models/Commons/comparefunctions.h
    src/Utils/appenviroment.h src/Utils/appenviroment.cpp
    applicationresource.qrc
    src/Models/mainwindowcontroller.h src/Models/mainwindowcontroller.cpp
    src/Utils/xlsxproxy.h src/Utils/xlsxproxy.cpp
    src/Models/Commons/storagedstructureselections.cpp src/Models/Commons/storagedstructureselections.h
    src/Models/Commons/sortedmethodselections.cpp src/Models/Commons/sortedmethodselections.h
)

qt_add_resources(StudentManagementApp "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

target_link_libraries(StudentManagementApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Widgets
)


add_subdirectory(DSALibraries)
add_subdirectory(QXlsx/QXlsx/)

target_link_libraries(StudentManagementApp PRIVATE DSALibraries)
target_link_libraries(StudentManagementApp PRIVATE QXlsx::QXlsx)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Models ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics
${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
set(QML_IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Import paths for Qt Creator's code model"
    FORCE
)

qt_add_qml_module(OverviewController
    URI "OverviewController"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/overviewcontroller.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/overviewcontroller.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/clisttablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/clisttablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/dlisttablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/dlisttablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/slisttablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/slisttablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/sortfiltertablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/sortfiltertablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/vectortablemodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/vectortablemodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/datatableprovider.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Overview/datatableprovider.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/student.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/student.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/studentvalidator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/studentvalidator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/comparefunctions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/comparefunctions.h
)


qt_add_qml_module(MainWindowController
    URI "MainWindowController"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/mainwindowcontroller.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/mainwindowcontroller.cpp
)

qt_add_qml_module(StatisticsController
    URI "StatisticsController"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/statisticscontroller.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/statisticscontroller.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/highestscoreslistview.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/highestscoreslistview.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/lowestscoreslistview.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/lowestscoreslistview.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/highestscoreslist.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/highestscoreslist.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/lowestscoreslist.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Statistics/lowestscoreslist.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/student.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/student.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/studentvalidator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/studentvalidator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/comparefunctions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/Commons/comparefunctions.h
)

if (BUILD_QDS_COMPONENTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/qmlcomponents)
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/qmlmodules)

if (LINK_INSIGHT)
    include(${CMAKE_CURRENT_SOURCE_DIR}/insight)
endif ()

include(GNUInstallDirs)
install(TARGETS StudentManagementApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# make IDEs aware of the QML import path
set(QML_IMPORT_PATH ${PROJECT_BINARY_DIR}/qml CACHE PATH
    "Path to the custom QML components defined by the project")
