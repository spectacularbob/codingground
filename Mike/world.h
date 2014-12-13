#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include "scene.h"
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
  std::vector<Drawable*> background;
  WorldMode mode;
  SceneLoader sceneLoader;
public:
  World();
  void add(Drawable * drawable);
  void addBackground(Drawable * background);
  void calculate();
  void setMode(WorldMode mode);
  void draw();
  void loadScene(SceneType index);
  void update();
  
};

#endif
