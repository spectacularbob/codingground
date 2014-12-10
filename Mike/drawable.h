#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>

class Drawable
{
protected:
    int x;
    int y;
    std::string figure;
public:
    void draw();
    void setPosition(int x, int y);
};

#endif