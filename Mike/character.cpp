#include "character.h"

void Character::draw() {
    mvprintw(y,x,head.c_str());
    mvprintw(y + 1,x,body.c_str());
}

Character::Character() {
    body = "|";
    head = "-";
    health = 10;
    facing = LEFT;
}

void Character::onCollision(Drawable * other) {
    if (other->whatAmI == HERO || other->whatAmI == ENEMY) {
        other->setVelocity(0,0);
    }
}

bool Character::collidesWith(Drawable * other)
{
  bool movingTowardOther = x + i == other->getX() && y + j == other->getY(); 
  bool otherMovingToward = other->getX() + other->getI() == x && other->getY() + other->getJ() == y;
  
  if((movingTowardOther && otherMovingToward) || 
     (i == 0 && j == 0 && otherMovingToward) ||
     (other->getI() == 0 && other->getJ() == 0 && movingTowardOther))
  {
   return true;
  }
  movingTowardOther = x + i == other->getX() && y + 1 + j == other->getY(); 
  otherMovingToward = other->getX() + other->getI() == x && other->getY() + other->getJ() == y + 1;
  
  if((movingTowardOther && otherMovingToward) || 
     (i == 0 && j == 0 && otherMovingToward) ||
     (other->getI() == 0 && other->getJ() == 0 && movingTowardOther))
  {
   return true;
  }
  return false;
}
