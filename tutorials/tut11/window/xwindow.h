#ifndef __XWINDOW_H__
#define __XWINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>

#include "window.h"

class WindowImpl;

class Xwindow {
	WindowImpl* impl;
 public:
  Xwindow(int width=500, int height=500);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.

  // Draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=Black);

  // Draws a string
  void drawString(int x, int y, std::string msg, int colour=Black);

  // Draws a line
  void drawLine(int x1, int y1, int x2, int y2); 

  // Draws an arc
  void drawArc(int x, int y, int width, int height, int angle1, int angle2);

  void fillArc(int x, int y, int width, int height, int angle1, int angle2, int colour);
  // Draws a circle
  void fillCircle(int x, int y, int r, int colour);
};

#endif
