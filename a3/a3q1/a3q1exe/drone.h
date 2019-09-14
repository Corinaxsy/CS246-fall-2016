#ifndef DRONE_H
#define DRONE_H

/* the drone will never visit more than 50 positions before
running out of fuel or otherwise breaking down.
*/
struct Position {
  int ew, ns;
  Position( int ew = 0, int ns = 0 );
};

struct Drone {
  Drone();
  ~Drone();
  void forward(); //Move the drone one unit forward.
  void backward(); //Moves the drone one unit backward.
  void left(); // Turns the drone 90 degrees to the left, while remaining in
               //  the same location.
  void right(); //Turns the drone 90 degrees to the right, while remaining in
                //  the same location.
  Position current() const; //returns the current position of the drone.
  int totalDistance() const; // Returns the total units of distance travelled by
                             //   the drone.
  int manhattanDistance() const; // Returns the "Manhattan distance" between the
                                //  current position and the origin
  bool repeated() const; // Returns true if the current position is one that the
                         //  drone has previously visited.

  // add your instance variables
 private:
  int orien; // N=0,E=1,S=2,W=3
  int distance;
  Position pos;
  struct Poslist;
  Poslist* l;
};

#endif
