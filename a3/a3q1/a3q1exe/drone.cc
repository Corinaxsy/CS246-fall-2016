#include "drone.h"
Position::Position(int a,int b): 
 ew{a},
 ns{b}
{}

struct Drone::Poslist{
 Position p;
 Poslist *next;
 Poslist *prev;
 Poslist();
 ~Poslist();
};

Drone::Poslist::Poslist(): p{0,0} , next{nullptr}, prev{nullptr}  {}
Drone::Poslist::~Poslist() { delete prev; }

Drone::Drone():
 orien{0},
 distance{0},
 pos{0,0},
 l{new Poslist()}
{}

Drone::~Drone() {
 delete l;
}

void Drone::forward() {
 if (orien == 0) { //North
  ++ pos.ns;
 } else if (orien == 1) { //East
  ++ pos.ew;
 } else if (orien == 2) { //South
  -- pos.ns;
 } else { // West
  -- pos.ew;
 }
 ++distance;
 Poslist *m = new Poslist();
 m->p = pos;
 l->next = m;
 m->prev = l;
 m->next = nullptr;
 l = m;
}


void Drone::backward() {
 if (orien == 0) { //North
  -- pos.ns;
 } else if (orien == 1) { //East
  -- pos.ew;
 } else if (orien == 2) { //South
  ++ pos.ns;
 } else { // West
  ++ pos.ew;
 }
 ++distance; 
 Poslist *m = new Poslist();
 m->p = pos;
 l->next = m;
 m->prev = l;
 m->next = nullptr;
 l = m;
}

void Drone::left() { 
 if (orien == 0) { //North
  orien = 3; // now West
 } else if (orien == 1) { //East
  orien = 0; // now North
 } else if (orien == 2) { //South
  orien = 1; // now East
 } else { // West
  orien = 2; // now South
 }
}


void Drone::right() {
 if (orien == 0) { //North
  orien = 1; // now East
 } else if (orien == 1) { //East
  orien = 2; // now South
 } else if (orien == 2){ //South
  orien = 3; // now West
 } else { // West
  orien = 0; // now North
 }
}

Position Drone::current() const {
 return pos;
}

int Drone::totalDistance() const {
 return distance;
}

int Drone::manhattanDistance() const {
 int absew = pos.ew;
 int absns = pos.ns;
 if (pos.ew < 0) {
  absew = 0 - pos.ew;
 }
 if (pos.ns < 0) {
  absns = 0 - pos.ns;
 }
 return absew+absns;
}



bool Drone::repeated() const {
 Poslist *temp;
 if (l->prev) {
  temp = l->prev;
  do {
   if ((temp->p.ew == pos.ew) && (temp->p.ns == pos.ns)) {
    return true;
   }
   temp = temp->prev;
  } while (temp);
 }
 return false;
}
