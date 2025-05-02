#ifndef NPC_H
#define NPC_H

#include <string>

class NPC {
private:
    std::string dialogue;
public:
    NPC(const std::string& dialogue);
    void interact();
};

#endif