cmake_minimum_required(VERSION 3.10)
project(Mandala)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)
find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(include)

file(GLOB SRC
        "src/model/*.cpp"
        "src/view/*.cpp"
        "include/model/*.hpp"
        "include/view/*.hpp"
        "ui/*.ui"
        )
add_executable(Mandala ${SRC} src/view/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets)
