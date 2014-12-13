//
//  hero.cpp
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#include "hero.h"

const int INITIAL_HEALTH = 10;

Hero::Hero() {
    head = "o";
    body = "|";
    weapon = 0;
    facing = RIGHT;
    whatAmI = HERO;
    health = INITIAL_HEALTH;
}

void Hero::cycleWeapon() {
    if (weaponVect.size() >= 1) {
        return;
    }
    weapon = (weapon + 1) % (weaponVect.size());
}

void Hero::addWeapon(Weapon* newWeapon) {
    for (int index = 0; index < weaponVect.size(); index++) {
        if (weaponVect[i].weaponType == newWeapon->weaponType) {
            if (weaponVect[i].hit < newWeapon->hit) {
                weaponVect[i].hit = newWeapon->hit;
            }
            return;
        }
    }
    weaponVect.push_back(newWeapon);
    newWeapon = NULL;
}

void Hero::addHealth(int healthReward) {
    health += healthReward;
}

void Hero::update() {
    
    if (health <= 0) {
        worldRef->endFight();
    }
}