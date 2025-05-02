### Description of the Class Diagram

- DungeonExplorer (Main Class):
  - This is the main game control class.
  - Contains references to other major game components such as Character, Dungeon, Combat, Inventory, GameState, and HowToPlay.
  - Provides methods to manage the game flow, such as starting the game (`start()`), handling the main loop (`mainLoop()`), managing character selection (`characterSelection()`), saving and loading the game state, and handling player loss (`handleLoss()`).

- Dungeon:
  - Manages the dungeon exploration mechanics.
  - Contains a room (and in the future would contain multiple rooms) represented as a vector of Room objects.
  - Provides methods such as explore().

- Room:
  - Represents an individual room within the dungeon.
  - Includes properties such as description, an Enemy, and an NPC.
  - Provides functionality for entering a room (`enter()`).

- Character (Base Class):
  - A base class for all playable characters (`Warrior`, 'Mage', `Rogue`).
  - Contains shared attributes such as name, health, and mana.
  - Offers shared behaviors such as displayStatus(), addItem(), and methods to attack or use special abilities.

- Warrior, Mage, Rogue (Derived Classes):
  - Derived from Character, these classes represent the unique player types.
  - Each class includes specialized abilities such as useShield() for Warrior, strikeTwice() for Mage, and healSelf() for Rogue.

- Combat:
  - Manages turn-based combat mechanics.
  - Provides methods for initiating combat (`engage()`), handling the player's turn (`playerTurn()`), and the enemy's turn (`enemyTurn()`).

- Inventory:
  - Handles the management of items available to the player globally.
  - Contains a collection of items and provides methods to add and use items.

- Item (Base Class):
  - Represents items in the game.
  - Contains derived classes such as Weapon, Armor, and Potion for different item types.

- GameState:
  - Tracks the game's current state, including the player's health, mana, and the current room index.
  - Provides methods to get and set these attributes.

- SaveLoad:
  - Manages saving and loading the game state using methods such as saveGame() and loadGame().

- HowToPlay:
  - Provides game instructions through a method called showInstructions().