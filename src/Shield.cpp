#include "Shield.h"
#include <iostream>
using namespace std;

Shield::Shield(int blockPower) : blockPower(blockPower) {}

int Shield::getBlockPower() const {
    return blockPower;
}

void Shield::block() {
    cout << "Blocking with power " << blockPower << "!" << endl;
}