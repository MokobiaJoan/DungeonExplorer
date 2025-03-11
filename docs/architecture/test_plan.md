Test Plan

 Testing Approach
1. Unit Tests  
   - Verify individual classes (e.g., Player, Enemy, `Inventory`) in isolation.  
   - Confirm methods like takeDamage(), useItem(), move() behave as expected.
2. Integration Tests  
   - Test how classes interact within a single scenario (e.g., Player enters a Room, fights Enemy, picks up `Item`).  
   - Check dungeon loading and room transitions.
3. Acceptance Tests  
   - Validate end-to-end gameplay: starting the game, exploring multiple rooms, defeating enemies, using items, and finishing a level.  
   - Confirm that the game loops correctly (e.g., victory/defeat conditions).

 Tools
- Google Test, Catch2, or doctest for automated unit testing.  
- Built-in assert statements for quick checks if needed.

 Coverage Goals
- Aim for 80%+ code coverage on critical classes (`Player`, Enemy, Room, `Dungeon`).  
- Ensure coverage of main logic paths for combat, item usage, and room transitions.

 Test Execution
- Local Environment: Developers run cmake --build followed by ctest or a similar command in VSCode/CLI.  
- CI Pipeline: Every commit triggers a build on GitHub Actions, automatically compiling and running all tests. Failures are flagged before merging pull requests.