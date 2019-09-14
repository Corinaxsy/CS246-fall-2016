#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include <vector>
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n):  
 gridSize{n} {
 vector<vector<char>>theDisplay;
 for (int r = 0; r < n; ++r) {
  vector<char> oneDim;
  for (int c = 0; c < n; ++c) {
   oneDim.emplace_back('_');
  }
  theDisplay.emplace_back(oneDim);
 }
}

void TextDisplay::notify(Subject &whoNotified) {
 Info tmp = whoNotified.getInfo();
 int row=0;
  for (auto it:theDisplay) {
    if (tmp.row == row) {
     if (tmp.state == false) {
      *(it.begin() + tmp.col) = '_';
     } else {
      *(it.begin() + tmp.col) = 'X';
     }
     break;
    }
   ++row;
  }
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
 for (auto it:td.theDisplay) {
  for (auto theone : it) {
   cout << theone;
  }
  cout << endl;
 }
 return out;
}
