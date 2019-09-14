#include <iostream>

using namespace std;

int value(int x){
	x += 10;
	return x;
}

int reference(int &y){
	y += 25;
	return y;
}

int pointer(int * z){
	*z += 42;
	return *z;
}

int main(){
	int c = 42;
	cout << "Call value(" << c << "):" << endl;
	cout << value(c) << endl;
	cout << "After value: " << c << endl;
	
	cout << "Call reference(" << c << ")" << endl;
	cout << reference(c) << endl;
	cout << "After reference: " << c << endl;

	cout << "Call pointer(&" << c << ")" << endl;
	cout << pointer(&c) << endl;
	cout << "After pointer: " << c << endl;
}
