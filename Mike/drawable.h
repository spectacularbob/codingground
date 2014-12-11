#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>

class Drawable
{
protected:
    int x;
    int y;
    std::string figure;
    int i;
    int j;
public:
    Drawable();
    void draw();
    void setPosition(int x, int y);
    int getX();
    int getY();
    int getI();
    int getJ();
    void setFigure(char figure);
    void setVelocity(int i, int j);
};

#endif
