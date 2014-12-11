#include "world.h"
#include "drawable.h"
#define XMIN 0
#define YMIN 0
#define XMAX 10
#define YMAX 10
Physics::Physics()
{
  mode = TOPVIEW;
}

void Physics::setMode(PhysicsMode mode)
{
  this->mode = mode;
}

void Physics::add(Drawable * drawable)
{
  drawables.push_back(drawable);
}

void Physics::calculate()
{
  for(int i = 0; i < drawables.size(); i++)
  {
	int newX = drawables[i]->getX() + drawables[i]->getI();
	int newY = drawables[i]->getY() + drawables[i]->getJ();
	if(newX < XMIN || newX > XMAX)
	{
	  newX = drawables[i]->getX();
	}
	if(newY < YMIN || newY > YMAX)
	{
	  newY = drawables[i]->getY();
	}
	drawables[i]->setPosition(newX,newY);
	drawables[i]->setVelocity(0,0);
  }
}

void Physics::draw()
{
  for(int i = 0; i < drawables.size(); i++)
  {
   drawables[i]->draw();
  }
}
