#include <iostream>
using namespace std;

int main() {
 int i;
 while (cin >> i) {
    if (cin.fail()) {
      if(cin.eof()) break;
      cout << "Invalid interger" << endl;
    } else }
      cout << i << endl;
  }
 }
}

