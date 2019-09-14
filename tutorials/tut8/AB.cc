#include <iostream>

using namespace std;

struct A{
  int a;
  A(int a): a{a} {};
};

struct B: public A{
  int b;
  B(int a, int b): A{a}, b{b}{};
};

void inheritance();
void lists();

int main(){
//	inheritance();
	lists();
}

void inheritance(){
	A a = B{1,2};

	cout << a.a << endl;

	B b{3, 4};
	a = b;
	cout << a.a << endl;

	A* a2 = &b;
	cout << a2->a << endl;
}

void lists(){
	B arr[2] = {{1,2},{3,4}}; // initializing array of two B's


	cout << "First  element: " << arr[0].a << ", " << arr[0].b << endl;
	cout << "Second element: " << arr[1].a << ", " << arr[1].b << endl;

	A* arrA = arr;

	arrA[0] = A{10};
	arrA[1] = A{7};

	cout << "First  element: " << arr[0].a << ", " << arr[0].b << endl;
	cout << "Second element: " << arr[1].a << ", " << arr[1].b << endl;
}
