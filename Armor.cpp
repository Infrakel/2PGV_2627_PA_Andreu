#include "Armor.hpp"
#include <cstdio>

int Armor::getDurability() const {
    return durability;
}

float Armor::getDamageReduction() const {
    return damageReduction;
}

float Armor::takeDamageReduction(float damage) {
    return damage * damageReduction;
}
