
#include <iostream>
#include "DungeonExplorer.h"
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Dungeon.h"
#include "Room.h"
#include "Combat.h"
#include "Inventory.h"
#include "GameState.h"
#include "HowToPlay.h"
#include "SaveLoad.h"
#include "Enemy.h"
#include "NPC.h"
#include "GameUI.h"

using namespace std;

DungeonExplorer::DungeonExplorer()
    : player(nullptr),
      dungeon(new Dungeon()),
      combat(new Combat()),
      inventory(new Inventory()),
      gameState(new GameState()),
      howToPlay(new HowToPlay()),
      saveLoad(new SaveLoad())
{}

DungeonExplorer::~DungeonExplorer()
{
    delete player;
    delete dungeon; 
    delete combat;
    delete inventory;
    delete gameState;
    delete howToPlay;
    delete saveLoad;
}

void DungeonExplorer::start()
{
    int choice = 0;

    while (true) {
        GameUI::clearScreen();
        GameUI::displayMainMenu();
        choice = GameUI::getIntInput();

        if (choice == 1) {
            characterSelection();
            mainLoop();
            break;
        }
        else if (choice == 2) {
            loadGame();
            mainLoop();
            break;
        }
        else if (choice == 3) {
            showHowToPlay();
            cout << "\nPress Enter to return to the main menu...";
            GameUI::getStringInput();
        }
        else if (choice == 4) {
            cout << "Exiting game. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void DungeonExplorer::characterSelection()
{
    GameUI::clearScreen();
    cout << "Select your character class:" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Rogue" << endl;
    cout << "Enter choice: ";
    int choice = GameUI::getIntInput();

    cout << "Enter your character's name: ";
    string name = GameUI::getStringInput();

    switch (choice) {
        case 1:  player = new Warrior(name); break;
        case 2:  player = new Mage(name);    break;
        case 3:  player = new Rogue(name);   break;
        default:
            cout << "Invalid choice, defaulting to Warrior." << endl;
            player = new Warrior(name);
    }

    gameState->setPlayerHealth(player->getHealth());
    gameState->setPlayerMana(player->getMana());

    cout << "Welcome, " << name << "! Your adventure begins now." << endl;
    cout << "Press Enter to continue...";
    GameUI::getStringInput();
}

void DungeonExplorer::mainLoop()
{

    if (dungeon->getRooms().empty()) {
        Room* room = new Room(
            "You find yourself in a dimly lit room. There is a health potion on a table "
            "and an enemy lurking in the shadows."
        );
        room->setEnemy(new Enemy("Goblin", 70, 23));
        room->setNPC(new NPC("Old Man: Beware of traps ahead!"));
        dungeon->addRoom(room);
    }


    for (size_t i = gameState->getCurrentRoomIndex(); i < dungeon->getRooms().size(); ++i) {
        GameUI::clearScreen();
        cout << "--- Entering Room " << (i + 1) << " ---" << endl;
        dungeon->getRooms()[i]->enter(inventory);
        gameState->setCurrentRoomIndex(static_cast<int>(i + 1));

        Enemy* enemy = dungeon->getRooms()[i]->getEnemy();
        if (enemy) {
            combat->setPlayer(player);
            combat->setEnemy(enemy);
            combat->engage();


            if (enemy->getHealth() <= 0) {
                dungeon->getRooms()[i]->setEnemy(nullptr);
            }

            if (player->getHealth() <= 0) {
                handleLoss();
                return;
            }
        }

        cout << "\nPress Enter to continue...";
        GameUI::getStringInput();
    }

    GameUI::clearScreen();
    cout << "Congratulations! You have completed the game." << endl;
    cout << "Summary of your achievements:" << endl;
    player->displayStatus();
    cout << "\nPress Enter to exit...";
    GameUI::getStringInput();
}

void DungeonExplorer::showHowToPlay()
{
    GameUI::clearScreen();
    howToPlay->showInstructions();
}

void DungeonExplorer::saveGame()
{
    gameState->setPlayerHealth(player->getHealth());
    gameState->setPlayerMana(player->getMana());
    saveLoad->saveGame(*gameState);
}

void DungeonExplorer::loadGame()
{
    *gameState = saveLoad->loadGame();
    if (player) {
        player->setHealth(gameState->getPlayerHealth());
        player->setMana(gameState->getPlayerMana());
    }
    cout << "Game loaded. Press Enter to continue...";
    GameUI::getStringInput();
}

void DungeonExplorer::handleLoss()
{
    GameUI::clearScreen();
    cout << "You have been defeated. Game Over." << endl;
    cout << "Press Enter to return to main menu...";
    GameUI::getStringInput();
}