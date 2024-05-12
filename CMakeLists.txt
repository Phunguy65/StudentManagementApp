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
    src/Models/student.h src/Models/student.cpp
    src/Utils/appenviroment.h src/Utils/appenviroment.cpp
    src/Models/slisttablemodel.h src/Models/slisttablemodel.cpp
    src/Models/vectortablemodel.h src/Models/vectortablemodel.cpp
    src/Models/clisttablemodel.h src/Models/clisttablemodel.cpp
    src/Models/dlisttablemodel.h src/Models/dlisttablemodel.cpp
    src/Models/sortfiltertablemodel.h src/Models/sortfiltertablemodel.cpp
    src/Models/storagedstructureselections.h src/Models/storagedstructureselections.cpp
    src/Models/overviewcontroller.h src/Models/overviewcontroller.cpp
    src/Models/filtercolumnselections.h src/Models/filtercolumnselections.cpp
    src/Models/sortedmethodselections.h src/Models/sortedmethodselections.cpp
    applicationresource.qrc
    src/Models/datatableprovider.h src/Models/datatableprovider.cpp
    src/Utils/studentvalidator.h src/Utils/studentvalidator.cpp
    src/Models/mainwindowcontroller.h src/Models/mainwindowcontroller.cpp
    src/Utils/xlsxproxy.h src/Utils/xlsxproxy.cpp

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

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Models ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
set(QML_IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Import paths for Qt Creator's code model"
    FORCE
)

qt_add_qml_module(OverviewController
    URI "OverviewTabController"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/overviewcontroller.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/overviewcontroller.cpp)

qt_add_qml_module(MainWindowController
    URI "MainWindowController"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/mainwindowcontroller.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/mainwindowcontroller.cpp)

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
