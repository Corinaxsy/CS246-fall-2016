#include "node.h"
#include <iostream>

//using namespace std;

using std::cout;
using std::endl;
using std::ostream;


ostream& operator<<(ostream& out, const Node& n){
	out << n.value;
	if ( n.next ){
		out << " <-> " << *(n.next);
	} 
	return out;
}

Node::Node(int begin, int end): value(begin){
	// set dir to so that adding it to begin will result in
	//   eventually reaching end
	int dir = 1;
	if ( begin > end ){
		dir = -1;
	}	
	
	while ( begin != end ){
		begin += dir;
		add(begin);
	}
}

void Node::add( int insert ){
	if ( next ){
		next->add(insert);
	} else {
		next = new Node{insert};
		next->prev = this;
	}
}

Node plus(Node n, int val){
	for ( Node* m = &n; m; m = m->next ){
		m->value += val;
	}
	return n;
}

Node::Node(int value): value{value} {}

Node::Node( const Node& n ): value{n.value}, next{ n.next ? new Node{*(n.next)}: nullptr }{
	if ( next ){
		next->prev = this;
	}
	cout << "copy ctor for value = " << value << endl;
}

Node::Node( Node&& n ): value{n.value}, next{ n.next }{
	if ( next ){
		next->prev = this;
	}
	n.next = nullptr;
	cout << "move ctor" << endl;
}


Node& Node::operator=( const Node& n ){
	if ( this != &n ){
		Node copy = n;

		// swap next nodes
		Node* temp = copy.next;
		copy.next = next;
		next = temp;

		prev = copy.prev;
		value = copy.value;
	}
	cout << "copy assignment operator" << endl;
	return *this;
}

Node& Node::operator=( Node&& n ){
	if ( this != &n ){

		// swap next nodes
		Node* temp = n.next;
		n.next = next;
		next = temp;

		prev = n.prev;
		value = n.value;
	}
	cout << "move assignment operator" << endl;
	return *this;
}


Node::~Node(){
	delete next;
}

