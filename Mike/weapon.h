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
#include "drawable.h"

enum WeapType {
    FIST,
    PISTOL,
    FIRE_BALL,
    ELEC_BALL
};

class Weapon : public Drawable {
public:
  Weapon();
  WeapType weaponType;
  int hit;
protected:
    std::string figure;
};

#endif /* defined(__nCurses__weapon__) */
