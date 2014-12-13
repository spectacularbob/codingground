#ifndef CHARACTER_H
#define CHARACTER_H

#include "drawable.h"

enum Direction {
    RIGHT,
    LEFT
};

class Character : public Drawable
{
private:
    std::string head;
    std::string body;
    int health;
    Direction facing = LEFT;
public:
    Character();
    void draw();
    void update();
};


#endif
