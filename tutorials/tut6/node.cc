#include "node.h"
#include <iostream>
#include <utility>


using std::cout;
using std::endl;
using std::ostream;
  

Node& Node::operator=(const Node& other){
  Node copy = other;

  Node* temp = next;
  next = copy.next;
  copy.next = temp;

  value = copy.value;

  return *this;
}
  
Node::Node(const Node& other):value{other.value}{
  cout << "copying value of " << value << endl;
  if ( other.next != nullptr ){
    next = new Node{*(other.next)};  // copy constructor
  }
}


Node::~Node(){
  delete next;
}

ostream& operator<<(ostream& out, const Node& n){
	out << n.value;
	if ( n.next ){
		out << " -> " << *(n.next);
	} 
	return out;
}

Node::Node(int value, Node* next): value(value), next(next){
}

Node::Node(int begin, int end): value(begin){

	// set dir to so that adding it to begin will result in
	//   eventually reaching end
	int dir = 1;
	if ( begin < end ){
		dir = -1;
	}	
	
	while ( begin != end ){
    next = new Node{end, next};
		end += dir;
	}
}

void Node::add( int insert ){
	if ( next ){
		next->add(insert);
	} else {
		next = new Node{insert};
	}
}

Node plus(Node n, int val){
	for ( Node* m = &n; m; m = m->next ){
		m->value += val;
	}
	return n;
}

