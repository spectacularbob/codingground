#include "weapon.h"
#include "character.h"
Weapon::Weapon() {
    hit = 1;
    figure = "-";
}

WeapType Weapon::getWeapon() {
    return weaponType;
}

void Weapon::onCollision(Drawable* other) {
    if (other->whatAmI == HERO || other->whatAmI == ENEMY) {
        Character * character = dynamic_cast<Character*>(other);
        if(character != 0)
	        character->health -= hit;
    }
    isDestroyed = true;
}
