#ifndef __nCurses__enemy__
#define __nCurses__enemy__

#include "character.h"
#include <vector>
#include "weapon.h"
enum EnemyLevel {
    PAWN,
    ELITE,
    BOSS,
};

class World;
class Hero;
class Enemy : public Character {
private:
    int healthReward;
    World* worldPtr;
    Hero* heroPtr;
    std::vector<WeapType> weapons;
    int currentWeapon;
    int level;
    int wait;
    int count;
public:
    Enemy(World* worldRef, Hero*, WeapType mainWeapon, EnemyLevel lev);
    void update();
    int calculateHealth();
};

#endif /* defined(__nCurses__enemy__) */
