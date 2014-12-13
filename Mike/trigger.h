#ifndef TRIGGER_H
#define TRIGGER_H

#include "drawable.h"
#include "scene.h"
class World;
class Trigger : public Drawable
{
  private:
   World * world;
   SceneType sceneType;

  public:
   Trigger(World * world, SceneType type);
   void update();
   void onCollision(Drawable * other);
};

#endif 
