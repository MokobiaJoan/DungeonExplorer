#include "GameUI.h"
#include <iostream>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void GameUI::displayHeader() {
    cout << "=======================================" << endl;
    cout << "         DUNGEON EXPLORER RPG          " << endl;
    cout << "=======================================" << endl;
}

void GameUI::displayMainMenu() {
    displayHeader();
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. How To Play" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void GameUI::displayCombatMenu() {
    cout << "\nYour turn. Choose an action:" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Special Ability" << endl;
    cout << "Enter your choice: ";
}

void GameUI::displayPrompt(const std::string &prompt) {
    cout << prompt;
}

int GameUI::getIntInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

std::string GameUI::getStringInput() {
    std::string input;
    getline(cin, input);
    return input;
}

void GameUI::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H";
#endif
}