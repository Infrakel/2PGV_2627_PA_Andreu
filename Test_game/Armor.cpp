#include "Armor.hpp"
#include <cstdio>
#include <algorithm>

float Armor::getDurability() const {
    return durability;
}

float Armor::getDamageReduction() const {
    return damageReduction;
}

void Armor::reduceDurability(float damage) {
    durability = std::max(0.0f, durability - damage);
}

float Armor::takeDamageReduction(float damage) {
    reduceDurability(damage);
    return damage * damageReduction;
}
