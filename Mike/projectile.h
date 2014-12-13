#ifndef __nCurses__projectile__
#define __nCurses__projectile__

#include "weapon.h"

class Projectile : public Weapon {
protected:
    int wait;
    int count;
    int velocity;
    
public:
    void update();
};

#endif /* defined(__nCurses__projectile__) */
