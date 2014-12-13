//
//  projectile.h
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#ifndef __nCurses__projectile__
#define __nCurses__projectile__

#include "weapon.h"

class Projectile : public Weapon {
private:
    int wait;
    int count;
    
public:
    void onCollision(Drawable * other);
    void attack();
    void update();
};

#endif /* defined(__nCurses__projectile__) */
