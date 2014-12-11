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

void World::calculate()
{
  for(int i = 0; i < drawables.size(); i++)
  {
	int newX = drawables[i]->getX() + drawables[i]->getI();
	int newY = drawables[i]->getY() + drawables[i]->getJ();
        bool collisionDetected = false;
        for(int j = i+1; j < drawables.size(); j++)
        {
	 if (drawables[j]->getX() == newX && drawables[j]->getY() == newY)
         {
           collisionDetected = true;
         }
	}
	if(newX < XMIN || newX > XMAX || collisionDetected)
	{
	  newX = drawables[i]->getX();
	}
	if(newY < YMIN || newY > YMAX || collisionDetected)
	{
	  newY = drawables[i]->getY();
	}


	drawables[i]->setPosition(newX,newY);
	drawables[i]->setVelocity(0,0);
  }
}

void World::draw()
{
  for(int i = 0; i < drawables.size(); i++)
  {
   drawables[i]->draw();
  }
}

void World::loadScene(SceneType type)
{
  sceneLoader.loadScene(this,type);  
}
