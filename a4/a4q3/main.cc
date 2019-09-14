#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;

  // You will need to make changes to this code.
  bool move = false;
  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
        g.init(n);
        cout << "noheap1" <<endl;
        move = false;
      }
      else if (cmd == "init") {
        int r;
        int c;
        while (true) {
         cin >> r >> c;
         if ((r < 0) || (c < 0)) break;
         cout << "noheap2" <<endl;
         g.init(r,c);
        }
        move = false;
        cout << g;
      }
      else if (cmd == "game") {
        cin >> moves;
        cout << moves << " moves left\n";
        
      }
      else if (cmd == "switch") {
        move = true;
        int r = 0, c = 0;
        cin >> r >> c;
        g.toggle(r,c);
        cout << g;
        --moves;
      }
      if (move) {
       if (g.isWon()) {
         cout << moves << " moves left\n";
         cout << "Won\n";
       } else {
         if (moves <= 0) {
          cout << moves << " moves left\n";
          cout << "Lost\n";
         } else {
          cout << moves << " moves left\n";
         }
       }
      }
    }
  }
  catch (ios::failure &) {
  }
}
