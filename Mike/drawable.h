#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>
#include <ncurses.h>

enum Type {
    HERO,
    HERO_WEP,
    ENEMY,
    ENEMY_WEP,
    SCENERY,
    TRIGGER
};

class Drawable
{
protected:
    int x;
    int y;
    std::string figure;
    int i;
    int j;
    bool isDestroyed;
public:
    Type whatAmI;
    Drawable();
    void setPosition(int x, int y);
    int getX();
    int getY();
    int getI();
    int getJ();
    void setFigure(char figure);
    void setVelocity(int i, int j);
    virtual void onCollision(Drawable * other) = 0;
    virtual bool collidesWith(Drawable * other);
    virtual void update() = 0;
    virtual void draw();
};

#endif
