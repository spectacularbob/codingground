//
//  weapon.h
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#ifndef __nCurses__weapon__
#define __nCurses__weapon__

#include <stdio.h>

enum WeapType {
    FIST,
    PISTOL,
    FIRE_BALL,
    ELEC_BALL
};

class Weapon : public Drawable {
protected:
    WeapType weaponType;
    std::string figure;
    int hit;
};

#endif /* defined(__nCurses__weapon__) */
