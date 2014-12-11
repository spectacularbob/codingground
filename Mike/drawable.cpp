#include "drawable.h"
#include <ncurses.h>

Drawable::Drawable()
{
	x = 0;
	y = 0;
	figure = "k";
	j = 0;
	k = 0;
}

void Drawable::draw()
{
	mvprintw(y,x,figure.c_str());
}

void Drawable::setFigure(char figure)
{
	this->figure = figure;
}

void Drawable::setVelocity(int j, int k)
{
	this->j = j;
	this->k = k;
}
