#include "dialog.h"
#include <ncurses.h>
#include <vector>
#include <sstream>

using namespace std;

Dialog::Dialog()
{
  visible = false;
}

void Dialog::setText(std::string text)
{ 
  istringstream tokenizeString(text);
  string temp;
  while(getline(tokenizeString,temp,'\n'))
  {
    lines.push_back(temp);
  }
}

void Dialog::draw()
{
  if(visible == false)
  {
    return;
  }
  std::string border = "//////////////////////////////";
  mvprintw(y,x,border.c_str());
  int i;
  for(i = 0; i < lines.size(); i++)
  {
    mvprintw(y+i+1,x,lines[i].c_str());
  }
  
  mvprintw(y+i+1,x,border.c_str());

}

void Dialog::show()
{
  visible = true;
}

void Dialog::hide()
{
  visible = false;
}

bool Dialog::isVisible()
{
  return visible;
}

void Dialog::update()
{

}

void Dialog::onCollision(Drawable * other)
{

}
