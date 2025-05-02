#include "NPC.h"
#include <iostream>
using namespace std;

NPC::NPC(const string& dialogue) : dialogue(dialogue) {}

void NPC::interact() {
    cout << "NPC says: " << dialogue << endl;
}