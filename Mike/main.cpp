#include <ncurses.h>
#include <unistd.h>
#include "world.h"
#include "character.h"
#include "scenery.h"
#define DELAY 30000

Physics physics;
Character dude;

void handleInput()
{
  char userIn = getch();
  switch(userIn)
  {
    case 'W':
    case 'w':
	dude.setVelocity(0,-1);
        break;
    case 'A':
    case 'a':
	dude.setVelocity(-1,0);
	break;
    case 'S':
    case 's':
	dude.setVelocity(0,1);
	break;
    case 'D':
    case 'd':
	dude.setVelocity(1,0);
	break;
  }
}

void initScene()
{
  Scenery * scenery = new Scenery();
  scenery->setPosition(1,1);
  physics.add(scenery);
}

int main(int argc, char *argv[]) {

  initscr();
  noecho();
  curs_set(FALSE);
  nodelay(stdscr, true);
  // Global var `stdscr` is created by the call to `initscr()`
  //getmaxyx(stdscr, max_y, max_x);
  char figure = 'a';
  physics.add(&dude);  
  initScene();
  while(1)
  {
    clear();
    handleInput();
    physics.calculate();
    physics.draw();
    
    refresh();
    usleep(DELAY);
  }
  endwin();
}
