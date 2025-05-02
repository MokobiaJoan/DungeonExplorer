
#ifndef GAMEUI_H
#define GAMEUI_H

#include <string>

class GameUI {
public:
    static void displayHeader();
    static void displayMainMenu();
    static void displayCombatMenu();
    static void displayPrompt(const std::string &prompt);
    static int getIntInput();
    static std::string getStringInput();
    static void clearScreen();
};

#endif