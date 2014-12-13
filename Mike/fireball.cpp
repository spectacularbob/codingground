#include "fireball.h"

Fireball::Fireball(int dir) {
    velocity = dir;
    hit = FIRE_DAMAGE;
    weaponType = FIRE_BALL;
    wait = 4;
}