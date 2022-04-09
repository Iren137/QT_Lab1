cmake_minimum_required(VERSION 3.20)
project(qt2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt2 main.cpp equation.h main_window.h main_window.cpp )
target_link_libraries(qt2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
