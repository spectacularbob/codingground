//
//  enemy.h
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#ifndef __nCurses__enemy__
#define __nCurses__enemy__

#include "character.h"

class Enemy : public Character {
private:
    int healthReward;
    World* worldPtr;
    Hero* heroPtr;
    vector<Weapon*> weapons;
    int currentWeapon;
    int level;
public:
    Enemy(World* worldRef, Hero*, Weapon* mainWeapon, int level);
    void update();
    void draw();
    void death();
};

#endif /* defined(__nCurses__enemy__) */
