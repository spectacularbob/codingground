#include <ncurses.h>
#include <unistd.h>
#include "physics.h"
#include "character.h"
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
	dude.setVelocity(0,1);
        break;
    case 'A':
    case 'a':
	dude.setVelocity(-1,0);
	break;
    case 'S':
    case 's':
	dude.setVelocity(0,-1);
	break;
    case 'D':
    case 'd':
	dude.setVelocity(1,0);
	break;
  }
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

  while(1)
  {
    clear();
    handleInput();
    dude.draw();
    dude.setFigure(figure);
    
    refresh();
    usleep(DELAY);
  }
  endwin();
}
