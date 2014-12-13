#include "weapon.h"

Weapon::Weapon() {
    hit = 1;
    figure = "-";
}

WeapType Weapon::getWeapon() {
    return weaponType;
}

void Weapon::onCollision(Drawable* other) {
    if (other->whatAmI == HERO || other->whatAmI == ENEMY) {
        other->health -= hit;
    }
    isDestroyed = true;
}