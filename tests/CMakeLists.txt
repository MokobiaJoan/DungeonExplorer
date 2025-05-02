
add_executable(TestCharacters
    TestCharacters.cpp
)

target_include_directories(TestCharacters
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(TestCharacters
    PRIVATE
        DungeonExplorerLib
)

add_test(NAME TestCharacters COMMAND TestCharacters)