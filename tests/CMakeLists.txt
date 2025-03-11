cmake_minimum_required(VERSION 3.31)

cmake cmake_policy(SET CMPOO48 NEW)

project(DungeonExplorer)


#Enabling C++17 or higher
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")
file(GLOB_RECURSE GAME_HEADERS "include/*.hpp")

add_library(DungeonExplorerLib ${GAME_SOURCES} ${GAME_HEADERS})

target_include_directories(DungeonExplorerLib PUBLIC include)


# main executable file
add_executable(DungeonExplorer src/main.cpp)





add_executable(DungeonExplorerTests test_main.cpp)
add_test(NAME BasicTests COMMAND runDungeonExplorerTests)

#testing subdirectory
enable_testing()
add_subdirectory(tests)