#include "scene.h"
#include "scenery.h"
#include "world.h"
#include "gameConstants.h"
void SceneLoader::loadScene(World * world, SceneType type)
{
  switch(type)
  {
  case START:
   loadStart(world);
   break;
  }
}

void SceneLoader::loadStart(World * world)
{
  for(int i =0; i <= MAX_HEIGHT; i++)
  {
    Scenery * scenery = new Scenery();
    scenery->setPosition(0,i);
    world->add(scenery);
    scenery = new Scenery();
    scenery->setPosition(MAX_WIDTH,i);
    world->add(scenery);
  }
}
