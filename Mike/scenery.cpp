#include "scenery.h"

Scenery::Scenery()
{
  figure = '|';
}

void Scenery::setFigure(char figure)
{
  this->figure = figure;
}

void Scenery::onCollision(Drawable * other)
{
   other->setVelocity(0,0);
}

void Scenery::update()
{

}
