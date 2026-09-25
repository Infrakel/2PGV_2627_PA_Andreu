#include <cstdio>
#include <string>
#include "Player.hpp"

// learn this, min minimum value, then make the difference between change and max, then take the maximum or minimun, undertand this
#define clamp(a,b,c)  std::min((c),std::max((a),(b)))

void Player::printPlayer() {
    printf("Speed: [%f]  |  Hp: [%d]  |  Gold: [%d] \n", speed, hp, gold);
}

void Player::increaseLife(int change) {
    hp = clamp(0, hp + change, maxHp);
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