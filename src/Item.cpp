#include "Item.h"

Item::Item(const std::string& name, const std::string& effect)
    : name(name), effect(effect) {}

Item::~Item() {}

std::string Item::getName() const {
    return name;
}

std::string Item::getEffect() const {
    return effect;
}