#include "scene.h"
#include "scenery.h"
#include "world.h"
#include "gameConstants.h"
#include "trigger.h"
void SceneLoader::loadScene(World * world, SceneType type)
{
  switch(type)
  {
  case START:
   loadStart(world);
   break;
  case ROOM_ONE:
   loadRoomOne(world);
   break;
  }
}

void SceneLoader::loadStart(World * world)
{
  for(int i =0; i <= MAX_HEIGHT; i++)
  {
    if(i == 5 || i == 6) continue;
    

    Scenery * scenery = new Scenery();
    scenery->setPosition(0,i);
    world->add(scenery);
    scenery = new Scenery();
    scenery->setPosition(MAX_WIDTH,i);
    world->add(scenery);
  }

  Trigger * trigger = new Trigger(world,ROOM_ONE);
  trigger->setPosition(0,5);
  world->add(trigger);
  trigger = new Trigger(world,ROOM_ONE);
  trigger->setPosition(0,6);
  world->add(trigger);

  Scenery * scenery = new Scenery();
  scenery->setPosition(15,15);
  scenery->setFigure('*');
  world->addBackground(scenery);
}

void SceneLoader::loadRoomOne(World * world)
{
	
}
