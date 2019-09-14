#ifndef __NODE__H___
#define __NODE__H___
#include <iostream>

struct Node{
	int value;
	Node* next = nullptr;

	Node(int value, Node* next = nullptr);
	Node(int begin, int end);
	
	Node( const Node& n );
	Node& operator=( const Node& n );
	~Node();

	void add( int insert );
};

std::ostream& operator<<(std::ostream& out, const Node& n);

Node plus(Node n, int val);
#endif
