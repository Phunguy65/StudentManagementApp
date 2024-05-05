cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(StudentManagementApp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.6 REQUIRED COMPONENTS Core Gui Qml Quick Widgets)
add_subdirectory(OpenXLSX)
add_subdirectory(SQLiteCpp)
add_subdirectory(DSALibraries)
if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Models ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils ${CMAKE_CURRENT_SOURCE_DIR}/src)
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

target_link_libraries(StudentManagementApp PRIVATE OpenXLSX::OpenXLSX)
target_link_libraries(StudentManagementApp PRIVATE SQLiteCpp sqlite3 pthread dl)
target_link_libraries(StudentManagementApp PRIVATE DSALibraries)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
set(QML_IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Import paths for Qt Creator's code model"
    FORCE
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
