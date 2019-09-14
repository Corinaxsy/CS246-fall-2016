#include "linkedList.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
	LinkedList list;

	list.insertAtFront(5);
	list.insertAtFront(10);
	list.insertAtBack(15);

	cout << list << endl;
}
