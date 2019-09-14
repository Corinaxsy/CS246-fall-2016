#include <iostream>
#include "node.h"


using std::cout;
using std::endl;
using std::ostream;

void example0();
void example1();
void example2();
void example3();
void example4();
void example5();

int main(){
	example1();
}


void example0(){
	Node* n1 = new Node{1,5};

	cout << *n1 << endl;

	delete n1;
}

void example1(){
	Node* n1 = new Node{6,1};

	// create n2 -> copy n1
	Node n2 = *n1;

	delete n1;

	cout << n2 << endl;
}

void example2(){
	Node* n1 = new Node{2,9};
	Node* n2 = new Node{4,2};

	// assign n2 to be equal to n1
	*n2 = *n1;

	delete n1;

	cout << *n2 << endl;

	delete n2;
}

void example3(){
	Node* n1 = new Node{0,7};
	
	*n1 = *n1;

	cout << n1 << endl;
}

void example4(){
	// create n1
	Node n1{0,10};

	Node n2 = plus(n1, 3);

	cout << n2 << endl;
}

void example5(){
	// create n1
	Node n1{5,7};

	Node n2{1,4};

	n2 = plus(n1, 4);

	cout << n2 << endl;
}
