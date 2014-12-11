#ifndef DIALOG_H
#define DIALOG_H

#include "drawable.h"
#include <vector>

class Dialog : public Drawable
{
private:
  std::vector<std::string> lines;
  bool visible;
public:
  Dialog();
  void setText(std::string text);
  void draw();
  bool isVisible();
  void show();
  void hide();
};

#endif
