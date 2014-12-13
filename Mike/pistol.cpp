#include "pistol.h"

Pistol::Pistol(int dir) {
    velocity = dir;
    hit = PISTOL_DAMAGE;
    weaponType = PISTOL;
    wait = 1;
}