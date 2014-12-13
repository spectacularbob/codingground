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
    Direction facing;
    int health;
public:
    void onCollision(Drawable * other);
    bool collidesWith(Drawable * other);
    int getHealth();
    int calcDir();
};


#endif
