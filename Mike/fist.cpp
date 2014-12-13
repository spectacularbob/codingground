//
//  fist.cpp
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#include "fist.h"

Fist::Fist() {
    wait = 1;
    count = 0;
    hit = 1;
    figure = "D";
}

void Fist::update() {
    if (count = 0) {
        setVelocity(1,0);
        count++;
    } else if (count < wait) {
        count++;
    }
    isDestroyed = true;
}

void Fist::onCollision(Drawable* other) {
    if (other->whatAmI == HERO || other->whatAmI == ENEMY) {
        other->health -= hit;
    }
    isDestroyed = true;
}