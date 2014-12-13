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

class Weapon : public Drawable {
protected:
    std::string figure;
    virtual void attack(Character*)=0;
};

#endif /* defined(__nCurses__weapon__) */
