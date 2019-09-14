#include <iostream>

using namespace std;

void foo(int x = 75){
	cout << x << endl;
}

void foo2(char c = 'A', int n = 32){
	char update = c + n;
	cout << update << endl;
}

int main(){
	foo();
	foo(10);
	foo2();
	foo2('D');
}
