#include "trigger.h"
#include "world.h"
Trigger::Trigger(World * world, SceneType type) : world(world), sceneType(type)
{
   figure = "`";
}

void Trigger::update()
{

}

void Trigger::onCollision(Drawable * other)
{
   if(other->whatAmI == HERO)
   {
     other->setVelocity(0,0);
     world->loadScene(sceneType);
   } 
}
