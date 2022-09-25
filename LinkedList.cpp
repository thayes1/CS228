// LinkedList.cpp
//Tyler Hayes


#include <stdlib.h>
#include "LinkedList.h"

// Default constructor, the list is empty to start
LinkedList::LinkedList() {
    head = NULL;

}

// Default destructor, must delete all nodesP

LinkedList::~LinkedList() {
    ListNode* ptr;

    for (ptr = head; head; ptr = head) {
        head = head->next
            delete ptr;
    }
}

// Add a node containing "value" to the front

void LinkedList::InsertFront(double value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Add a node containing "value" to position "index"

void LinkedList::Insert(double value, unsigned int index) {
    curr = NULL;
    prev = NULL;
    Node* temp, newNode = NULL; 

    int pos = 0;

    if (index == 0)
        InsertFront(value);

    if (index > GetLength() + 1)
        throw 0;

    curr = head;
    else {
        while (curr != NULL) { //while we are not at the end of our list
            if (pos == index) { //when we reach the position we want 
                newNode = new Node; //create a new node
                newNode->data = value; //give it the user value
                newNode->next = curr; //asign new nodes next to index's node
                prev->next = newNode; //asign the previous node's next to new node 
            }
            prev = curr;
            curr = curr->next; //move over one index 
            pos++;
        }
    }
}


// Return value at position "index"

double LinkedList::GetNode(unsigned int index) {
    curr = NULL;
    curr = head;
    int pos = 0;

    if (index > GetLength())
        throw 0;

    while (curr != NULL) {
        if (pos == index) {
            return curr->data;
        }
        curr = curr->next;
        pos++;
    }

    
}


// Return the index of the node containing "value"

unsigned int LinkedList::Search(double value) {
    curr = NULL;
    curr = head;
    int pos = 0;

    while (curr != NULL) {
        if (curr->data == value) {
            return pos;
        }
        curr = curr->next;
        pos++;
    }

    throw 0;
}


// Delete the node at position "index", return the value that was there

double LinkedList::DeleteNode(unsigned int index) {
    int pos;
    double info;
    curr, prev = NULL;

    if (index > GetLength())
        throw 0;

    if (index == 0) {
        info = head->data;
        head = head->next;
        return info;
    }

    curr = head;
    while (curr != NULL) {
        if (pos == index) {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        prev = curr;
        curr = curr->next;
        pos++;
    }
    return false;
}

// This function reverses the order of all nodes so the first node is now the
// last and the last is now the first (and all between). So a list containing 
// (4, 0, 2, 11, 29) would be (29, 11, 2, 0, 4) after Reverse() is called.
// Outcome:
//List: 4-0-2-11-29
//Reverse()
//List: 29-11-2-0-4
void LinkedList::Reverse() {
    Node* temp = NULL;
    curr = NULL;

        curr = head;
        while (curr != NULL) {
            Node* newNode = new Node;
            newNode->data = curr->data;
            newNode->next = temp;
            temp = newNode;
            curr = curr->next;
                
            DeleteNode(0);

 
        }
        head = temp;

}

// Return the number of nodes in the list

int LinkedList::GetLength() {
    i = 0;
    while (value != NULL) {
        i++;
        value = value->next;
    }
    return i;
}
