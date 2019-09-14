#ifndef ___LINKED__LIST___
#define ___LINKED__LIST___

#include <iostream>

class LinkedList{
  public:
    LinkedList();

    void insertAtFront(int value);
    void insertAtBack(int value);

    void remove(int index);

    int size() const;

    friend std::ostream& operator<<(std::ostream& out, const LinkedList& ll);

    LinkedList( const LinkedList& ll );
    LinkedList( LinkedList&& ll );
    LinkedList& operator=( const LinkedList& ll );
    LinkedList& operator=( LinkedList&& ll );
    ~LinkedList();

  private:
    int numNodes = 0;

    struct Node;
    Node* head = nullptr;
		Node* tail = nullptr;

};

#endif
