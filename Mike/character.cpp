#include "character.h"

void Character::draw() {
    mvprintw(y,x,head.c_str());
    mvprintw(y + 1,x,body.c_str());
}

Character::Character() {
    body = "|";
    head = "-";
    health = 10;
}

void Character::update() {
    
}