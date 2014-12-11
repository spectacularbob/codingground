#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
class Drawable;

enum WorldMode
{
  TOPVIEW,
  SIDEVIEW
};

class World
{
private:
  std::vector<Drawable*> drawables;
  WorldMode mode;
public:
  World();
  void add(Drawable * drawable);
  void calculate();
  void setMode(WorldMode mode);
  void draw();
};

#endif
