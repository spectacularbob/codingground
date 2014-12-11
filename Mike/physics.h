#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
class Drawable;

class Physics
{
private:
  std::vector<Drawable*> drawables;
public:
  void add(Drawable * drawable);
};

#endif
