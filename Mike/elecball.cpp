//
//  elecball.cpp
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#include "elecball.h"

ElecBall::ElecBall(int dir) {
    velocity = dir;
    hit = ELEC_DAMAGE;
    weaponType = ELEC_BALL;
    wait = 4;
}