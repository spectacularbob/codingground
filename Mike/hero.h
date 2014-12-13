//
//  hero.h
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#ifndef __nCurses__hero__
#define __nCurses__hero__

#include "character.h"
#include "weapon.h"
#include <vector>

class Hero : public Character {
private:
    int weapon;
    std::vector<Weapon*> weaponVect;
    
public:
    Hero();
    void draw();
    void cycleWeapon();
    virtual void update();
    virtual void onCollision(Drawable * other);
    void addWeapon(Weapon*);
    void addHealth(int healthReward);
    void death();
};

#endif /* defined(__nCurses__hero__) */
