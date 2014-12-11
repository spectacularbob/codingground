#include <ncurses.h>
#include <unistd.h>
#include "world.h"
#include "character.h"
#include "scenery.h"
#include "dialog.h"

#define DELAY 30000

World world;
Character dude;
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
    case '|':
        shutDown = true;
        break;
  }
}

void initScene()
{
  dude.setPosition(1,1);
  world.add(&dude);  
  for(int i =0; i < 10; i++)
  {
    Scenery * scenery = new Scenery();
    scenery->setPosition(0,i);
    world.add(scenery);
  }
  dialog.setPosition(10,10);
  dialog.setText("Controls\nMove with WASD\nSpacebar advances dialogs\nShift and then | quits");
  dialog.show();
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
    clear();
    handleInput();
    world.calculate();
    world.draw();
    dialog.draw(); 
    refresh();
    usleep(DELAY);
  }
  endwin();
}
