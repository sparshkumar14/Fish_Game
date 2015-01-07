#ifndef __View__
#define __View__

#include "GameObject.h"
#include "CartPoint.h"


const int view_maxsize = 20;

class View
{
 public:
  View();
  void clear();
  void plot(GameObject* ptr);
  void draw();

 private:
  int size;
  double scale;
  CartPoint origin;
  char grid[view_maxsize][view_maxsize][2];
  bool get_subscripts(int &ix, int &iy, CartPoint location);

};


#endif