//
//  enemy.cpp
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#include "enemy.h"

Enemy::Enemy(World* worldRef, Hero* dude, Weapon* mainWeapon, int level) {
    int healthReward;
    heroPtr = dude;
    worldPtr = worldRef;
    weapons.push_back(mainWeapon);
    int currentWeapon;
    int level;
    std::string head;
    std::string body;
    int health;
    Direction facing;
}
void update() {
    if (health <= 0 || heroPtr->health <= 0) {
        worldRef->endFight();
    }
}

void draw() {
    
}