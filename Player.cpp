#include <cstdio>
#include <cassert>
#include <string>
#include "Player.hpp"

// learn this, min minimum value, then make the difference between change and max, then take the maximum or minimun, undertand this
#define clamp(a,b,c)  std::min((c),std::max((a),(b)))

void Player::printPlayer() {
    printf("Speed: [%f]  |  Hp: [%d]  |  Gold: [%d] \n", speed, hp, gold);
}

void Player::printArmorStats() {
    for (int i = 0; i < maxArmors; i++) {
        if (armors[i] != nullptr) {
            printf("Armor stats: \n durability: [%f] \n damage reduction: [%f] position in elements: [%d] \n", armors[i]->getDurability(), armors[i]->getDamageReduction(), i);
        }
    }
}

void Player::increaseLife(int change) {
    hp = clamp(0, hp + change, maxHp);

    printf("HP: [%d]   change [%d] \n", hp, change);
}

void Player::increaseSpeed(int change) {
    speed = clamp(minSpeed, speed * change, maxSpeed);
}

void Player::decreaseSpeed(int change) {
    speed = clamp(minSpeed, speed - change, maxSpeed);
}

bool Player::spendMoney(int change) {
    if(gold-change < 0) return false;
    gold -= change;
    return true;
}

void Player::equipArmor(Armor armor_to_set) {

    for (int i = 0; i < maxArmors; i++) {
        if (armors[i] == nullptr) {

            armors[i] = new Armor(armor_to_set);
            break;
        }
    }
}

void Player::reasignArmors(int slot_number) {

    // do it before logic to delete on memory
    if (slot_number < 0 || slot_number > maxArmors) { return; }

    // add logic to delete only
    delete armors[slot_number];
    armors[slot_number] = nullptr;
    
    for (int i = 0; i < maxArmors; i++) {

        if (armors[i] == nullptr) { 

            if (armors[i + 1] == nullptr) { return; };
            
            armors[i] = armors[i + 1];
            armors[i + 1] = nullptr;
        };
    }

    // i dont need to check if it is null because i dont care, i can just move the object between them
    // if i do i - 1, there is a problem, i need to start on i = 1

    /*for (int i = 1; i < maxArmors + 1; i++) {
        armors[i - 1] = armors[i];
        armors[i] = nullptr;
    }*/
}

void Player::unequipArmor(int slot_number) {

    assert(slot_number >= 0 && slot_number <= maxArmors);
    assert(armors[slot_number] != nullptr);
    // logic to cook something
    reasignArmors(slot_number);
}

Armor* Player::getArmor(int slot) {
    return armors[slot];
}