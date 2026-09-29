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

    float total_damage = 0;

    for (int i = 0; i < 10; i++) {
        if (p.getArmor(i) != nullptr) {
            total_damage = p.getArmor(i)->takeDamageReduction(150);
            break;
        }
    }

    p.increaseLife(-total_damage);
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

    // logic to equip the armor
    Armor armor = Armor(50, 0.2f);
    hero.equipArmor(armor);
    hero.printArmorStats();
    hero.printArmorStats();


    //int precioArmadura = 200;
    /*if(hero.spendMoney(precioArmadura)) {
        printf("armor buyed! \n");
        //equipar armadura
    } else {
        printf("cant buy armor! \n");
    }*/

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
    hero.printPlayer();
    //printf("Se va a desequipar!! ");
    hero.unequipArmor(0);
    //printf("Hecho \n");
    fallInLava(hero);
    hero.printPlayer();

    return 0;
}