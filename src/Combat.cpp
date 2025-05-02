#include "Combat.h"
#include "Enemy.h"
#include "GameUI.h"
#include <iostream>
using namespace std;

Combat::Combat() : player(nullptr), enemy(nullptr), turnCounter(0) {}

Combat::~Combat() {}

void Combat::setPlayer(Character* p) {
    player = p;
}

void Combat::setEnemy(Enemy* e) {
    enemy = e;
}

void Combat::engage() {
    if (!player || !enemy) return;
    cout << "An enemy appears! Prepare for combat." << endl;
    while (player && enemy && player->getHealth() > 0 && enemy->getHealth() > 0) {
        cout << "\n-- Combat Turn " << ++turnCounter << " --" << endl;
        playerTurn();
        if (enemy->getHealth() <= 0) {
            cout << "You defeated the enemy!" << endl;
            break;
        }
        enemyTurn();
        if (player->getHealth() <= 0) {
            cout << "You have been defeated by the enemy." << endl;
            break;
        }
    }
}

void Combat::playerTurn() {
    GameUI::displayCombatMenu();
    int choice = GameUI::getIntInput();
    if (choice == 1) {
        player->attack();
        enemy->setHealth(enemy->getHealth() - 20);
        cout << "Enemy health is now " << enemy->getHealth() << endl;
    } else if (choice == 2) {
        player->specialAbility();
        enemy->setHealth(enemy->getHealth() - 25);
        cout << "Enemy health is now " << enemy->getHealth() << endl;
    } else {
        cout << "Invalid choice. You lose your turn." << endl;
    }
}

void Combat::enemyTurn() {
    if (!enemy) return;
    cout << "Enemy's turn." << endl;
    enemy->decideAction(player);
}