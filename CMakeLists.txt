cmake_minimum_required(VERSION 3.31)

cmake_policy(SET CMP0048 NEW)

project(DungeonExplorer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")
file(GLOB_RECURSE GAME_HEADERS "include/*.hpp")

add_library(DungeonExplorerLib ${GAME_SOURCES} ${GAME_HEADERS})

target_include_directories(DungeonExplorerLib PUBLIC include)

add_executable(DungeonExplorer src/main.cpp)

target_link_libraries(DungeonExplorer PRIVATE DungeonExplorerLib)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

if(TEST_SOURCES)
add_executable(runTests ${TEST_SOURCES})

target_link_libraries(runTests PRIVATE DungeonExplorerLib)

add_test(NAME DungeonExplorerTests COMMAND runTests)
endif()