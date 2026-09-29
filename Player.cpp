#include <cstdio>
#include <string>
#include "Player.hpp"

// learn this, min minimum value, then make the difference between change and max, then take the maximum or minimun, undertand this
#define clamp(a,b,c)  std::min((c),std::max((a),(b)))

void Player::printPlayer() {
    printf("Speed: [%f]  |  Hp: [%d]  |  Gold: [%d] \n", speed, hp, gold);
}

void Player::printArmorStats() {
    for (int i = 0; i < 10; i++) {
        if (armors[i] != nullptr) {
            printf("Armor stats: \n durability: [%d] \n damage reduction: [%f] \n", armors[i]->getDurability(), armors[i]->getDamageReduction());
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

    for (int i = 0; i < 10; i++) {
        if (armors[i] == nullptr) {

            armors[i] = new Armor(armor_to_set);
            break;
        }
    }
}

void Player::unequipArmor(int slot_number) {

    // delete first, then point to nullptr
    delete armors[slot_number];
    armors[slot_number] = nullptr;
}

Armor* Player::getArmor(int slot) {
    return armors[slot];
}