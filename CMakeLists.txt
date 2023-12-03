cmake_minimum_required(VERSION 3.5)

project(HomeworkQt5 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Stopwatch.h
        Stopwatch.cpp
)

    qt_add_executable(HomeworkQt5
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

target_link_libraries(HomeworkQt5 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                                                Qt6::Core)




if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HomeworkQt5)
endif()
