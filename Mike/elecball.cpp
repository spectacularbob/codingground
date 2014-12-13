#include "elecball.h"

ElecBall::ElecBall(int dir) {
    velocity = dir;
    hit = ELEC_DAMAGE;
    weaponType = ELEC_BALL;
    wait = 4;
}