#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "xwindow.h"
#include "window.h"
#include "bigWindow.h"

using namespace std;


Xwindow::Xwindow(int width, int height): impl{new BigWindow{width,height}} {}
//Xwindow::Xwindow(int width, int height): impl{new WindowImpl{width,height}} {}

Xwindow::~Xwindow() {
	delete impl;
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(impl->d, impl->gc, impl->colours[colour]);
  XFillRectangle(impl->d, impl->w, impl->gc, impl->getX(x), impl->getY(y), impl->getX(width), impl->getY(height));
  XSetForeground(impl->d, impl->gc, impl->colours[Black]);
}


void Xwindow::drawString(int x, int y, string msg, int colour) {
  XSetForeground(impl->d, impl->gc, impl->colours[colour]);
  XDrawString(impl->d, impl->w, impl->gc, impl->getX(x), impl->getY(y), msg.c_str(), msg.length());
  XSetForeground(impl->d, impl->gc, impl->colours[Black]);
}

void Xwindow::drawLine(int x1, int y1, int x2, int y2){
  XDrawLine(impl->d, impl->w, impl->gc, impl->getX(x1), impl->getY(y1), impl->getX(x2), impl->getY(y2));
}

void Xwindow::drawArc(int x1, int y1, int width, int height, int sAngle, int eAngle){
	XDrawArc(impl->d,impl->w,impl->gc,impl->getX(x1),impl->getY(y1),impl->getX(width),
						impl->getY(height),sAngle*64,eAngle*64);
}

void Xwindow::fillArc(int x, int y, int width, int height, int angle1, int angle2, int colour){	
  XSetForeground(impl->d, impl->gc, impl->colours[colour]);
  XFillArc(impl->d,impl->w,impl->gc, impl->getX(x), impl->getY(y), impl->getX(width),
			impl->getY(height),angle1*64,angle2*64);
  XSetForeground(impl->d, impl->gc, impl->colours[Black]);
}

void Xwindow::fillCircle(int x, int y, int r, int colour){
  XSetForeground(impl->d, impl->gc, impl->colours[colour]);
  XFillArc(impl->d, impl->w, impl->gc, impl->getX(x), impl->getX(y),
								impl->getX(r), impl->getY(r),0*64,360*64);
  XSetForeground(impl->d, impl->gc, impl->colours[Black]);
}

