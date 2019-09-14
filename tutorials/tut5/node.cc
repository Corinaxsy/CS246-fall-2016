#include "node.h"
#include <iostream>
#include <utility>

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

Node::Node(int value): value{value} {}

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

