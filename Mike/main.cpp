#include <ncurses.h>
#include <unistd.h>
#include "world.h"
#include "character.h"
#include "dialog.h"
#include "gameConstants.h"
#include "scene.h"
#include "hero.h"
#define DELAY 30000

World world;
bool shutDown = false;
Dialog dialog;

void handleInput()
{
  char userIn = getch();

  if(userIn == ' ')
  {
    dialog.hide();
  }
  if(dialog.isVisible())
  {
    return;
  }
  
  switch(userIn)
  {
    case 'W':
    case 'w':
	world.getHero()->setVelocity(0,-1);
        break;
    case 'A':
    case 'a':
	world.getHero()->setVelocity(-1,0);
	break;
    case 'S':
    case 's':
	world.getHero()->setVelocity(0,1);
	break;
    case 'D':
    case 'd':
        world.getHero()->setVelocity(1,0);
	break;
    case '|':
        shutDown = true;
        break;
  }
}

void initScene()
{
  world.loadScene(START);
  dialog.setPosition(10,10);
  dialog.setText("Controls\nMove with WASD\nSpacebar advances dialogs\nShift and then | quits");
  dialog.show();
}

bool checkScreenSize()
{
   int x;
   int y;
   getmaxyx(stdscr,y,x);
   if(x < MAX_WIDTH || y < MAX_HEIGHT)
   {
     mvprintw(0,0,
     "The screen is too small, please make it bigger.\nCurrent (%i,%i)\nNeeds to be (%i,%i)"
     ,x,y,MAX_WIDTH,MAX_HEIGHT);
     refresh();
     return false;
   }

   return true;
}

int main(int argc, char *argv[]) 
{
  initscr();
  noecho();
  curs_set(FALSE);
  nodelay(stdscr, true);
  // Global var `stdscr` is created by the call to `initscr()`
  //getmaxyx(stdscr, max_y, max_x);
  initScene();
  while(shutDown == false)
  {
    world.update();
    clear();
    if(checkScreenSize() == false)
    { 
      usleep(DELAY);
      continue;
    }
    handleInput();
    world.calculate();
    world.draw();
    dialog.draw(); 
    refresh();
    usleep(DELAY);
  }
  endwin();
}
