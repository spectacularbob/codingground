#ifndef __nCurses__weapon__
#define __nCurses__weapon__

#include "drawable.h"

const int FIST_DAMAGE = 1;
const int PISTOL_DAMAGE = 3;
const int FIRE_DAMAGE = 8;
const int ELEC_DAMAGE = 12;

enum WeapType {
    FIST,
    PISTOL,
    FIRE_BALL,
    ELEC_BALL
};

class Weapon : public Drawable {
public:
  Weapon();
  WeapType weaponType;
  int hit;
protected:
    std::string figure;
    int hit;
    int velocity;
public:
    WeapType getWeapon();
    void onCollision(Drawable * other);
};

#endif /* defined(__nCurses__weapon__) */
