#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "drawable.h"

enum SceneType
{
  START,
  ROOM_ONE,
  ROOM_TWO
};

class World;
class SceneLoader
{
public:
  void loadScene(World * world, SceneType type);
private:
  World * world;
  std::vector<Drawable*> scenery;
  void loadStart();
  void loadRoomOne();
  void loadRoomTwo();
  void createBush(int x, int y);
  void createVWall(int x, int y);
  void createHWall(int x, int y);
  void createRoomTrigger(int x, int y, SceneType type);
};

#endif
