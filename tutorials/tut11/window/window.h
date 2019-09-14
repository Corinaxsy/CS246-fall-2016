#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>

enum {White=0, Black, Red, Green, Blue, Cyan, Yellow, Magenta, Orange, Brown, DarkGreen}; // Available colours.

struct WindowImpl{
  Display *d;
  Window w;
  int s;
  GC gc;
  unsigned long colours[11];
	int xMult;
	int yMult;

	WindowImpl(int width, int height, int xMult = 1, int yMult = 1);
	~WindowImpl();
	
	int getX(int);
	int getY(int);
};

#endif
