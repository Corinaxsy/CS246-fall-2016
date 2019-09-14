#include <iostream>
using namespace std;

struct Vec {
  int x, y;
  Vec(int x=0, int y=0): x{x}, y{y} {
    cout << "Basic ctor" << endl;
  }
  Vec(const Vec &other): x{other.x}, y{other.y} {
    cout << "Copy ctor" << endl;
  }
  Vec(Vec &&other): x{other.x}, y{other.y} {
    cout << "Move ctor" << endl;
  }
  Vec & operator = (const Vec &other) {
   x = other.x;
   y = other.y;
   cout << "Copy assignment" << endl;
  }
  Vec & operator = (const Vec &&other) {
   x = other.x;
   y = other.y;
   cout << "Move assignment" << endl;
  }
  ~Vec() {
   cout << "Destructor" << endl;
  }
};

Vec makeAVec() { return {0, 0}; }

int main() {
  Vec v1(1,2);
  Vec v2{1,2};
  v2 = {v1};
}
