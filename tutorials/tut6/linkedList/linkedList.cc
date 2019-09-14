#include "linkedList.h"
#include <iostream>
#include <utility>


using std::cout;
using std::endl;
using std::ostream;

struct LinkedList::Node{
  int value;
  Node* next = nullptr;

  Node(int value, Node* next = nullptr);
  Node(int begin, int end);

  Node( const Node& n );
  Node( Node&& n );
  Node& operator=( const Node& n );
  Node& operator=( Node&& n );
  ~Node();

  void add( int insert );
  Node* last();
};

LinkedList::LinkedList(){}


void LinkedList::insertAtFront(int value){
  head = new Node{value, head};
  if ( ! tail ){
    tail = head;
  }
  ++numNodes; 
}

void LinkedList::insertAtBack(int value){
  Node* temp = new Node{value};

  // if tail exists, make temp the new tail
  if ( tail ){
    tail->next = temp;
    temp = tail;
  } else {
    // otherwise, temp is the only node and should be the head and the tail
    head = tail = temp;
  }
  ++numNodes; 
}

void LinkedList::remove(int index){
  if ( index < numNodes ){
    Node* temp = head;
    if ( index == 0 ){
      head = head->next;
      temp->next = nullptr;
    } else {
      int count = 0;
      while ( count + 1 < index ){
        temp = temp->next;
        ++count;
      }
      Node* cur = temp;
      temp = temp->next;
      cur->next = temp->next;
      temp->next = nullptr;
    }
    delete temp;
    --numNodes;
  }
}

int LinkedList::size() const{
  return numNodes;
}

LinkedList::Node* LinkedList::Node::last(){
  if ( next ) return next->last();
  return this;
}

LinkedList::LinkedList( const LinkedList& ll ): numNodes(ll.numNodes){
  if ( ll.head ){
    head = new Node{*ll.head};
    tail = head->last();
  }	
}

LinkedList::LinkedList( LinkedList&& ll ): numNodes{ll.numNodes},
  head{ll.head}, tail{ll.tail}{
    ll.head = nullptr;
    ll.tail = nullptr;
  }

LinkedList& LinkedList::operator=( const LinkedList& ll ){
  LinkedList copy = ll;

  using std::swap;

  swap(head, copy.head);
  swap(tail, copy.tail);
  swap(numNodes, copy.numNodes);

  return *this;
}

LinkedList& LinkedList::operator=( LinkedList&& ll ){
  using std::swap;

  swap(head, ll.head);
  swap(tail, ll.tail);
  swap(numNodes, ll.numNodes);

  return *this;
}

LinkedList::~LinkedList(){
  delete head;
}



LinkedList::Node& LinkedList::Node::operator=(const LinkedList::Node& other){
  Node copy = other;

  Node* temp = next;
  next = copy.next;
  copy.next = temp;

  value = copy.value;

  return *this;
}

LinkedList::Node::Node(const LinkedList::Node& other):value{other.value}{
  cout << "copying value of " << value << endl;
  if ( other.next != nullptr ){
    next = new Node{*(other.next)};  // copy constructor
  }
}


LinkedList::Node::~Node(){
  delete next;
}

ostream& operator<<(ostream& out, const LinkedList& ll){
  LinkedList::Node *curr = ll.head;
  if ( curr ){
    out << curr->value;
    curr = curr->next;
  }
  while ( curr ){
    out << " -> " << curr->value;
    curr = curr->next;
  } 
  return out;
}

LinkedList::Node::Node(int value, LinkedList::Node* next): value(value), next(next){
}

LinkedList::Node::Node(int begin, int end): value(begin){

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

void LinkedList::Node::add( int insert ){
  if ( next ){
    next->add(insert);
  } else {
    next = new Node{insert};
  }
}

