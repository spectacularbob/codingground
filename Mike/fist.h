//
//  fist.h
//  nCurses
//
//  Created by Mike Pomazal on 12/12/14.
//
//

#ifndef __nCurses__fist__
#define __nCurses__fist__

#include "weapon.h"

class Fist : public Weapon {
private:
    int wait;
    int count;
public:
    void attack();
    void upadate();
};

#endif /* defined(__nCurses__fist__) */
