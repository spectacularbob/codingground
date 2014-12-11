#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
class Drawable;

enum PhysicsMode
{
  TOPVIEW,
  SIDEVIEW
};

class Physics
{
private:
  std::vector<Drawable*> drawables;
  PhysicsMode mode;
public:
  Physics();
  void add(Drawable * drawable);
  void calculate();
  void setMode(PhysicsMode mode);
  void draw();
};

#endif
