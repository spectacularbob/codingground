#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include "scene.h"
#include "drawable.h"
#include "hero.h"
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
  SceneLoader sceneLoader;
  Hero * hero;
public:
  WorldMode mode;
  World();
  ~World();
  void add(Drawable * drawable);
  void addBackground(Drawable * background);
  void calculate();
  void setMode(WorldMode mode);
  void draw();
  void loadScene(SceneType index);
  void update();
  void spawnWeapon(Drawable*);
  Hero * getHero();
  void endFight();
};

#endif
