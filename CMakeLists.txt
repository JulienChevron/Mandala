cmake_minimum_required(VERSION 3.12)
project(Mandala)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)
find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(include)

add_executable(Mandala
        src/view/MainWindow.cpp
        src/view/BottomWidget.cpp
        src/view/CenterWidget.cpp
        src/view/TopWidget.cpp
        include/view/MainWindow.hpp
        include/view/BottomWidget.hpp
        include/view/CenterWidget.hpp
        include/view/TopWidget.hpp
        ui/MainWindow.ui
        src/view/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets)
