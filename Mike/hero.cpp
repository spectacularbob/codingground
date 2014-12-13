//
//  hero.cpp
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#include "hero.h"

Hero::Hero() {
    head = "o";
    body = "|";
    weapon = 0;
    facing = RIGHT;
    whatAmI = HERO;
}

void Hero::cycleWeapon() {
    if (weaponVect.size() >= 1) {
        return;
    }
    weapon = (weapon + 1) % (weaponVect.size());
}

