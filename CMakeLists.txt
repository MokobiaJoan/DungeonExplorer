


cmake_minimum_required(VERSION 3.10)
project(DungeonExplorer)

#Enabling C++17 or higher

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# main executable file
add_executable(DungeonExplorer src/main.cpp)

#testing subdirectory

add_executable(DungeonExplorerTests ${test_main.cpp})
add_test(NAME BasicTests COMMAND DungeonExplorerTests)

enable_testing()
add_subdirectory(tests)