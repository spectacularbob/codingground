#ifndef SCENE_H
#define SCENE_H

enum SceneType
{
  START
};

class World;

class SceneLoader
{
public:
  void loadScene(World * world, SceneType type);
private:
  void loadStart(World * world);
};

#endif
