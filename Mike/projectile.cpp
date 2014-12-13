//
//  projectile.cpp
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#include "projectile.h"

void Projectile::update() {
    if (count < wait) {
        count++;
        return;
    }
    count = 0;
    setVelocity(velocity,0);
}