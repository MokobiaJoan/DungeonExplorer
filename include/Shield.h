#ifndef SHIELD_H
#define SHIELD_H

class Shield {
private:
    int blockPower;
public:
    Shield(int blockPower);
    int getBlockPower() const;
    void block();
};

#endif