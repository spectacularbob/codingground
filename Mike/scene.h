#ifndef SCENE_H
#define SCENE_H

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
  void loadStart(World * world);
  void loadRoomOne(World * world);
};

#endif
