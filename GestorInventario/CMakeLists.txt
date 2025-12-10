cmake_minimum_required(VERSION 3.16)
project(GestorInventario LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6 or Qt5
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql REQUIRED)

add_executable(gestor
    src/main.cpp
    src/MainWindow.cpp
    src/Component.cpp
    src/DatabaseManager.cpp
    src/ReportGenerator.cpp
    src/MainWindow.h
    src/Component.h
    src/DatabaseManager.h
    src/ReportGenerator.h
    resources.qrc
)

# Use Qt libraries
target_link_libraries(gestor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

add_executable(test_headless
    src/test_headless.cpp
    src/Component.cpp
    src/DatabaseManager.cpp
    src/ReportGenerator.cpp
    src/Component.h
    src/DatabaseManager.h
    src/ReportGenerator.h
)
target_link_libraries(test_headless PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Handle UI files if needed (none provided in the prompt, UI is built in code)

# Strip symbols for smaller size in Release
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(UNIX)
        set_target_properties(gestor PROPERTIES LINK_FLAGS "-s")
    endif()
endif()
