#include "character.h"

void Character::draw() {
    mvprintw(y,x,head.c_str());
    mvprintw(y + 1,x,body.c_str());
}

Character::Character() {
    body = "|";
    head = "-";
    health = 10;
    facing = LEFT;
}

void Character::onCollision(Drawable * other) {
    if (other->whatAmI == HERO || other->whatAmI == ENEMY) {
        other->setVelocity(0,0);
    }
}

