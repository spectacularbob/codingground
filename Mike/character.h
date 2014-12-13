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
    Direction facing;
public:
    Character();
    int health;
    void onCollision(Drawable * other);
    bool collidesWith(Drawable * other);
    int getHealth();
    int calcDir();
    void draw();
};


#endif
