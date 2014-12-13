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
    void cycleWeapon();
    void update();
    void onCollision(Drawable * other);
    void addWeapon(Weapon*);
    void addHealth(int healthReward);
};

#endif /* defined(__nCurses__hero__) */
