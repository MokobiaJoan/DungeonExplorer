Non-Functional Requirements

1. Performance:
   - The game should run smoothly on standard desktop hardware with minimal memory overhead.
2. Platform Compatibility:
   - Must compile and run on Windows, Linux, and macOS using standard C++17 (or later).
3. Maintainability:
   - Follow consistent naming conventions and modular design practices to ensure the codebase is clean and easily extensible.
4. User Interface:
   - Start with a command-line interface that clearly displays game state and prompts.
   - Design the architecture to allow for a future transition to a graphical interface without major refactoring.





### Game Scenario

#### Starting the Game

1. Launching the Game:
   - The player launches the game and selects "New Game" from the main menu.
   - The start() method of the DungeonExplorer class is called.

#### Character Selection

2. Character Selection:
   - The player is prompted to choose a character class: Warrior, Mage, or Rogue.
   - The player reads the descriptions and selects any character of their choice.
   - The player enters their character's name and confirms the selection.
   - The characterSelection() method of the DungeonExplorer class is called, creating an instance of the chosen character's class.

#### Entering the Room

3. Entering the Room:
   - The game starts, and the player finds themselves in a single room.
   - The enter() method of the Room class is called, describing the room's contents.
   - The room contains a health potion and an enemy.

#### Interacting with Inventory

4. Finding Items:
   - The player finds a health potion in the room.
   - The player adds the potion to their inventory using the addItem() method of the Inventory class.

5. Using Items:
   - The player takes damage from a trap in the room.
   - The player uses a health potion to restore health using the useItem() method of the Inventory class.

#### Combat Encounter

6. Combat Encounter:
   - The player encounters an enemy in the room.
   - The engage() method of the Combat class is called to start the combat.
   - During the player's turn, the player uses any of its abilities(methods) in combat.
   - The enemy takes its turn, and the combat continues until the enemy is defeated.

#### Ending the Game

7. Ending the Game:
   - After defeating the enemy, the player successfully completes the game.
   - The game provides a summary of the player's achievements and experience points earned.