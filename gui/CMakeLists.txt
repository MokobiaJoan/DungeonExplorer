cmake_minimum_required(VERSION 3.16)
project(DungeonExplorerGUI)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)


find_package(Qt6 COMPONENTS Widgets REQUIRED)


add_executable(DungeonExplorerGUI
   main.cpp
   MainWindow.h
   MainWindow.cpp
)


# include your engine headers
target_include_directories(DungeonExplorerGUI PRIVATE
   ${CMAKE_SOURCE_DIR}/include
)


target_link_libraries(DungeonExplorerGUI PRIVATE
   Qt6::Widgets
)

