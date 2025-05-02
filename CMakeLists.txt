cmake_minimum_required(VERSION 3.16)
project(DungeonExplorer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE GAME_SOURCES src/*.cpp)
list(FILTER GAME_SOURCES EXCLUDE REGEX "./gui/.")

add_library(DungeonExplorerLib STATIC
    ${GAME_SOURCES}
)

target_include_directories(DungeonExplorerLib
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

find_package(Qt6 COMPONENTS Widgets QUIET)
if (Qt6_FOUND)
    set(QtWidgets_LIB Qt6::Widgets)
else()
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    set(QtWidgets_LIB Qt5::Widgets)
endif()

add_executable(DungeonExplorerGUI
    gui/main.cpp
    gui/MainWindow.cpp
)

target_include_directories(DungeonExplorerGUI
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(DungeonExplorerGUI
    PRIVATE
        DungeonExplorerLib
        ${QtWidgets_LIB}
)

enable_testing()
add_subdirectory(tests)