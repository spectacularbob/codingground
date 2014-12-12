#ifndef CHARACTER_H
#define CHARACTER_H

#include "drawable.h"

class Character : public Drawable
{
private:
    std::string head;
    std::string body;
public:
    Character();
    void draw();
};


#endif
