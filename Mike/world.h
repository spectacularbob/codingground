#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include "scene.h"
#include "hero.h"
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
  Hero hero;
public:
  World();
  void add(Drawable * drawable);
  void addBackground(Drawable * background);
  void calculate();
  void setMode(WorldMode mode);
  void draw();
  void loadScene(SceneType index);
  void update();
  Hero * getHero();
  
};

#endif
