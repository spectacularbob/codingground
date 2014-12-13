#ifndef CHARACTER_H
#define CHARACTER_H

#include "drawable.h"

enum Direction {
    RIGHT,
    LEFT
};

class Character : public Drawable
{
protected:
    std::string head;
    std::string body;
    int health;
    Direction facing;
public:
    Character();
    virtual void onCollision(Drawable * other);
    bool collidesWith(Drawable * other);
    void draw();
};


#endif
