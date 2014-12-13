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
    Direction facing;
public:
    virtual void update() = 0;
    void onCollision(Drawable * other);
    bool collidesWith(Drawable * other);
};


#endif
