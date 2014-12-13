#include "fireball.h"

FireBall::FireBall(int dir) {
    velocity = dir;
    hit = FIRE_DAMAGE;
    weaponType = FIRE_BALL;
    wait = 4;
}
