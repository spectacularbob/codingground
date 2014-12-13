#include "scene.h"
#include "scenery.h"
#include "world.h"
#include "gameConstants.h"
#include "trigger.h"
#include "enemy.h"
void SceneLoader::loadScene(World * world, SceneType type)
{
  this->world = world;
  for(int i = 0; i < scenery.size(); i++)
  {
    delete scenery[i];
  } 
  scenery.clear();
  switch(type)
  {
  case START:
   loadStart();
   break;
  case ROOM_ONE:
   loadRoomOne();
   break;
  case ROOM_TWO:
   loadRoomTwo();
   break;
  }
}

void SceneLoader::loadStart()
{
  for(int i =0; i <= MAX_HEIGHT; i++)
  {
    if(i == 5 || i == 6) continue;
 
    createVWall(0,i);
    createVWall(MAX_WIDTH,i);    
  }
  for(int i = 0; i <= MAX_WIDTH; i++)
  {
    createHWall(i,0);
    createHWall(i,MAX_HEIGHT);
  }

  createRoomTrigger(0,5,ROOM_ONE);
  createRoomTrigger(0,6,ROOM_ONE);
  createRoomTrigger(MAX_WIDTH,5,ROOM_TWO);
  createRoomTrigger(MAX_WIDTH,6,ROOM_TWO);

  createBush(15,15);

  world->getHero()->setPosition(5,5);
}

void SceneLoader::loadRoomOne()
{
  Enemy * enemy = new Enemy(world,world->getHero(),FIST, PAWN);
  enemy->setPosition(10,13);
  world->add(enemy);
  for(int i =10; i <= MAX_HEIGHT; i++)
  {
    createVWall(0,i);
    if(i == 20 || i == 21) continue;
    createVWall(MAX_WIDTH,i);    
  }

  for(int i = 0; i <= MAX_WIDTH; i++)
  {
    createHWall(i,10);
    createHWall(i,MAX_HEIGHT);
  }
  createRoomTrigger(MAX_WIDTH,20,START);
  createRoomTrigger(MAX_WIDTH,21,START);

  createBush(15,15);

  world->getHero()->setPosition(MAX_WIDTH-1,20);
}

void SceneLoader::loadRoomTwo()
{
  for(int i =10; i <= MAX_HEIGHT; i++)
  {
   
    if(i != 20 && i != 21)
    {
      createVWall(0,i);
    } 
    createVWall(MAX_WIDTH,i);    
  }

  for(int i = 0; i <= MAX_WIDTH; i++)
  {
    createHWall(i,10);
    createHWall(i,MAX_HEIGHT);
  }
  createRoomTrigger(0,20,START);
  createRoomTrigger(0,21,START);

  createBush(15,15);

  world->getHero()->setPosition(1,20);
}

void SceneLoader::createBush(int x, int y)
{
  Scenery * scenery = new Scenery();
  scenery->setPosition(x,y);
  scenery->setFigure('*');
  world->addBackground(scenery);
  this->scenery.push_back(scenery);
}

void SceneLoader::createHWall(int x, int y)
{
  Scenery * scenery = new Scenery();
  scenery->setPosition(x,y);
  scenery->setFigure('-');
  world->add(scenery);
  this->scenery.push_back(scenery);
}

void SceneLoader::createVWall(int x, int y)
{
  Scenery * scenery = new Scenery();
  scenery->setPosition(x,y);
  scenery->setFigure('|');
  world->add(scenery);
  this->scenery.push_back(scenery);
}
  
void SceneLoader::createRoomTrigger(int x, int y, SceneType type)
{
  Trigger * trigger = new Trigger(world,type);
  trigger->setPosition(x,y);
  world->add(trigger);
  this->scenery.push_back(trigger);
}
