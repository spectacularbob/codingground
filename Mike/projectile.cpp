#include "projectile.h"

void Projectile::update() {
    if (count < wait) {
        count++;
        return;
    }
    count = 0;
    setVelocity(velocity,0);
}