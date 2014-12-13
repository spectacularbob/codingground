#ifndef __nCurses__enemy__
#define __nCurses__enemy__

#include "character.h"

enum EnemyLevel {
    PAWN,
    ELITE,
    BOSS,
};

class Enemy : public Character {
private:
    int healthReward;
    World* worldPtr;
    Hero* heroPtr;
    vector<Weapon*> weapons;
    int currentWeapon;
    int level;
    int wait;
    int count;
public:
    Enemy(World* worldRef, Hero*, Weapon* mainWeapon, int lev);
    void update();
    int calculateHealth();
};

#endif /* defined(__nCurses__enemy__) */
