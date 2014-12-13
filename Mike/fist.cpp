#include "fist.h"

Fist::Fist(int velo) {
    wait = 1;
    count = 0;
    hit = FIST_DAMAGE;
    figure = "D";
    weaponType = FIST;
    velocity = velo;
}

void Fist::update() {
    if (count = 0) {
        setVelocity(velocity,0);
        count++;
    } else if (count < wait) {
        count++;
    }
    isDestroyed = true;
}

