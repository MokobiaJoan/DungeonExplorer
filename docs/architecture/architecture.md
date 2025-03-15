### Architectural Structure


DungeonExplorer: The main game class that manages the overall game flow. It holds references to the Character, Dungeon, Combat, Inventory, GameState, and HowToPlay components. It provides methods to start the game, handle the main game loop, manage character selection, show instructions, save/load the game, and handle losses.

 Character: The base class for all characters in the game, including Warrior, Mage, and Rogue. It includes methods to display the character's status, add items to the inventory, attack, and use special abilities. Each derived class provides its own unique methods.

Dungeon: Manages the dungeon exploration. It contains a vector of Room objects and provides a method to explore the dungeon.

 Room: Represents a room in the dungeon. It includes a description of the room, an enemy, and an NPC. It provides a method to enter the room.

 Combat: Manages combat interactions between the player and enemies. It provides methods to engage in combat, handle player turns, and handle enemy turns.

 Inventory: Manages the items that a character carries. It provides methods to add and use items.

 Item: The base class for all items in the game. Derived classes include Weapon, Armor, and Potion, each with their own unique methods.

 GameState: Represents the state of the game at any given point. It includes methods to get and set the player's health, mana, and current room index.

 SaveLoad: Handles saving and loading the game state. It provides methods to save and load the game state.

 HowToPlay: Provides instructions on how to play the game. It includes a method to show the instructions.