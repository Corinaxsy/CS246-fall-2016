#ifndef DRONE_H
#define DRONE_H

struct Position {
  int ew, ns;
  Position( int ew = 0, int ns = 0 );
};

struct Drone {
  Drone();
  ~Drone();
  void forward(); 
  void backward(); 
  void left();
  void right();
  Position current() const;
  int totalDistance() const;
  int manhattanDistance() const;
  bool repeated() const;

  // add your instance variables
 private:
  int orien; // N=0,E=1,S=2,W=3
  int distance;
  Position pos;
  struct Poslist;
  Poslist* l;
};

#endif
