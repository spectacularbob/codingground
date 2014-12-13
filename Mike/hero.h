#ifndef __nCurses__hero__
#define __nCurses__hero__

#include "character.h"
#include "weapon.h"
#include <vector>

class World;

class Hero : public Character {
private:
    int weapon;
    std::vector<Weapon*> weaponVect;
    World * worldRef;    
public:
    Hero(World * world);
    void cycleWeapon();
    void update();
    void addWeapon(Weapon*);
    void addHealth(int healthReward);
};

#endif /* defined(__nCurses__hero__) */
