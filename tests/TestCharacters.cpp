#include <cassert>
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"

int main() {
    Warrior w("Alice");
    assert(w.getName() == "Alice");
    assert(w.getHealth() == 120);
    assert(w.getMana() == 30);

    Mage m("Bob");
    assert(m.getName() == "Bob");
    assert(m.getHealth() == 80);
    assert(m.getMana() == 100);

    Rogue r("Cara");
    assert(r.getName() == "Cara");
    assert(r.getHealth() == 90);
    assert(r.getMana() == 50);

    return 0;
}