#include <iostream>
#include "grid.h"
#include "info.h"
#include <vector>
using namespace std;

Grid::Grid() {}

Grid::~Grid() { clearGrid(); }

void Grid::clearGrid() {
 if (initgrid) {
  delete td;
  for (auto vec : theGrid) {
   vec.clear();
  }
  theGrid.clear();
 }
}

bool Grid::isWon() const {
 for (auto therow: theGrid) {
  for (auto theone:therow) {
   if (theone.getState() == true) {
     return false;
   }
  }
 }
 return true;
}

void Grid::init(int n) {
 clearGrid();
 initgrid = true;
 vector<vector<Cell>>theGrid;
  for (int r = 0; r < n; ++r) {
   vector<Cell> oneDim;
   for (int c = 0; c < n; ++c) {
    Cell * newcell = new Cell();
    newcell->setCoords(r,c);
    newcell->attach(newcell);
    oneDim.emplace_back(*newcell);
    cout << "oneNode " << r << ' ' << c << endl;
   }
   theGrid.emplace_back(oneDim);
  }
 gridSize = n;
 td = new TextDisplay{gridSize};
 (theGrid.front()).front().attach(td);
}

void Grid::turnOn(int r, int c) {
}

void Grid::toggle(int r, int c) {
  for (int row = 0; row < gridSize; ++row) {
   vector<Cell> oneDim = *(theGrid.begin() + row);
   for (int col = 0; col < gridSize; ++col) {
    Cell theone = *(oneDim.begin() + col);
    if ((r == row) && (c == col)) {
      theone.toggle();
    }
   }
  }
}

void Grid::init(int r, int c) {
 theGrid[r][c].setOn();
}

ostream &operator<<(ostream &out, const Grid &g) {
 cout << *(g.td) << endl;
 return out;
}
