#ifndef __NODE__H___
#define __NODE__H___
#include <iostream>

struct Node{
	int value;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node(int value);
    
	Node(int begin, int end);

	void add( int insert );
    ~Node(){
        delete next;
    }
};

std::ostream& operator<<(std::ostream& out, const Node& n);

Node plus(Node n, int val);
#endif
