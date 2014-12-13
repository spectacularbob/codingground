#include "drawable.h"
#include <cmath>

Drawable::Drawable()
{
	x = 0;
	y = 0;
	figure = "k";
	i = 0;
	j = 0;
        isDestroyed = false;
        whatAmI = NONE;
}

void Drawable::draw()
{
	mvprintw(y,x,figure.c_str());
}

void Drawable::setFigure(char figure)
{
	this->figure = figure;
}

void Drawable::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Drawable::setVelocity(int i, int j)
{
	this->i = i;
	this->j = j;
}

int Drawable::getX()
{
	return x;
}

int Drawable::getY()
{
	return y;
}

int Drawable::getI()
{
	return i;
}

int Drawable::getJ()
{
	return j;
}

bool Drawable::collidesWith(Drawable * other)
{
  bool movingTowardOther = x + i == other->x && y + j == other->y; 
  bool otherMovingToward = other->x + other->i == x && other->y + other->j == y;
  
  if((movingTowardOther && otherMovingToward) || 
     (i == 0 && j == 0 && otherMovingToward) ||
     (other->i == 0 && other->j == 0 && movingTowardOther))
  {
   return true;
  }
  return false;

}
