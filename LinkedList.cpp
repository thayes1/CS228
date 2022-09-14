// LinkedList.cpp
//Tyler Hayes

#include <stdlib.h>
#include "LinkedList.h"

// Default constructor, the list is empty to start

LinkedList::LinkedList() {
    int data;
    Node* next;
    data = 0;

}

// Default destructor, must delete all nodes

LinkedList::~LinkedList() {
    ListNode* ptr;

    for (ptr = head; head; ptr = head) {
        head = head->next
            delete ptr;
    }
}

// Add a node containing "value" to the front

void LinkedList::InsertFront(double value) {
    Node* value = NULL;


}

// Add a node containing "value" to position "index"

void LinkedList::Insert(double value, unsigned int index) {
    Node* value = index; 

}


// Return value at position "index"

double LinkedList::GetNode(unsigned int index) {

}


// Return the index of the node containing "value"

unsigned int LinkedList::Search(double value) {

}


// Delete the node at position "index", return the value that was there

double LinkedList::DeleteNode(unsigned int index) {

}

// This function reverses the order of all nodes so the first node is now the
// last and the last is now the first (and all between). So a list containing 
// (4, 0, 2, 11, 29) would be (29, 11, 2, 0, 4) after Reverse() is called.

void LinkedList::Reverse() {
       
}

// Return the number of nodes in the list

int LinkedList::GetLength() {

}
