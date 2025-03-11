Description
- DungeonExplorer (Main): The core “engine” that runs the game loop—updates logic, handles transitions between states, and coordinates all subsystems.  
- UI/Renderer Layer: Responsible for displaying game information (text or graphics) and capturing player input.  
- Combat/AI Module: Contains logic for how enemies behave, how combat is initiated and resolved, and how AI decisions are made (e.g., pathfinding, aggression levels).  
- Entities & Systems: Houses core objects (Player, Enemy, Items) and systems (Movement, Inventory, etc.) that govern game state and interactions.  
- Data/Assets: Contains external resources (like level data, item definitions, or images/sounds if a GUI is used).