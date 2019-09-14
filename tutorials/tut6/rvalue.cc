#include <iostream>

using namespace std;

void check(const int& value){
  cout << "check called with lvalue " << value << endl;
}


void check(const int&& value){
  cout << "check called with rvalue " << value << endl;
}


int main(){
  int x = 5;
//  int& lref = 7;
  int& lref2 = x;

  int&& rref = 10;
//  int&& rref2 = x;

  cout << rref << endl;
  cout << &rref << endl;

  check(lref2); //lvalue
  check(rref); //lvalue
  check(17);   //rvalue

}


