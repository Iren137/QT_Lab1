cmake_minimum_required(VERSION 3.20)
project(qt1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt1 main.cpp card.h lhs_widget.cpp lhs_widget.h main_window.cpp main_window.h randomizer.h randomizer.cpp )
target_link_libraries(qt1
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
