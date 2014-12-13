#ifndef SCENERY_H
#define SCENERY_H

#include "drawable.h"

class Scenery : public Drawable
{
public:
  Scenery();
  void setFigure(char figure);
  void onCollision(Drawable * drawable);
};

#endif
