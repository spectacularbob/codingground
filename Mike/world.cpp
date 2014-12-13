#include "world.h"
#include "drawable.h"
#include "gameConstants.h"

#define XMIN 0
#define YMIN 0
#define XMAX MAX_WIDTH
#define YMAX MAX_HEIGHT
World::World()
{
  mode = TOPVIEW;
}

void World::setMode(WorldMode mode)
{
  this->mode = mode;
}

void World::add(Drawable * drawable)
{
  drawables.push_back(drawable);
}

void World::addBackground(Drawable * drawable)
{
  background.push_back(drawable);
}

void World::calculate()
{
  for(int i = 0; i < drawables.size(); i++)
  {
	for(int j = i+1; j < drawables.size(); j++)
        {
	  if(drawables[i]->collidesWith(drawables[j]))
          {
	     drawables[i]->onCollision(drawables[j]);
             drawables[j]->onCollision(drawables[i]);    	
          }
	}	
  }

  for(int i =0; i < drawables.size(); i++)
  {
	int originalX = drawables[i]->getX();
	int originalY = drawables[i]->getY();
	int newX = originalX + drawables[i]->getI();
	int newY = originalY + drawables[i]->getJ();
	drawables[i]->setPosition(newX,newY);
        drawables[i]->setVelocity(0,0);
  }       
}

void World::draw()
{ 
  for(int i = 0; i < background.size(); i++)
  {
    background[i]->draw();
  }

  for(int i = 0; i < drawables.size(); i++)
  {
   drawables[i]->draw();
  }
}

void World::loadScene(SceneType type)
{
  drawables.clear();
  background.clear();
  sceneLoader.loadScene(this,type);  
}

void World::update() {
    for (int index = 0; index < drawables.size(); index++){
        drawables[index]->update();
    }
}

Hero * World::getHero()
{
   return hero;
}

