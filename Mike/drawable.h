#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>

class Drawable
{
protected:
    int x;
    int y;
    std::string figure;
    int j;
    int k;
public:
    Drawable();
    void draw();
    void setPosition(int x, int y);
    void setFigure(char figure);
    void setVelocity(int j, int k);
};

#endif
