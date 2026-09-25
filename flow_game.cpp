// Player.h
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdio>
#include <string>
#include "Player.hpp"

#endif

void buyPotion(Player& p) {
    if(p.spendMoney(30)) {
        p.increaseLife(40);
        printf("potion buyed! \n");
    } else {
        printf( "cant buy potion! \n");
    }
}

void fallInLava(Player& p) {
    p.increaseLife(-150);
}

void pickUpBoots(Player& P) {
    P.increaseSpeed(10);
}

void deleteBoots(Player& P) {
    P.decreaseSpeed(30);
}

int main() {
    Player hero;
    hero.printPlayer();

    int precioArmadura = 200;
    if(hero.spendMoney(precioArmadura)) {
        printf("armor buyed! \n");
        //equipar armadura
    } else {
        printf("cant buy armor! \n");
    }

    buyPotion(hero);
    hero.printPlayer();

    buyPotion(hero);
    hero.printPlayer();

    pickUpBoots(hero);
    hero.printPlayer();
    deleteBoots(hero);
    hero.printPlayer();
    pickUpBoots(hero);
    hero.printPlayer();

    fallInLava(hero);
    fallInLava(hero);
    hero.printPlayer();

    return 0;
}