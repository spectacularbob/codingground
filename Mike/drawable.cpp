#include "drawable.h"

Drawable::Drawable()
{
	x = 0;
	y = 0;
	figure = "k";
	i = 0;
	j = 0;
    isDestroyed = false;
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
