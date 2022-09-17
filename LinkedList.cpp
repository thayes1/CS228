// LinkedList.cpp
//Tyler Hayes


#include <stdlib.h>
#include "LinkedList.h"

// Default constructor, the list is empty to start
LinkedList::LinkedList() {
    head = NULL;
    cur = NULL;
    next = NULL;
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
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Add a node containing "value" to position "index"

void LinkedList::Insert(double value, unsigned int index) {
    Node* value = index; 
    Node* newNode = new Node;
    newNode->value = *index;
    *index = newNode;
}


// Return value at position "index"

double LinkedList::GetNode(unsigned int index) {
    return *index;
}


// Return the index of the node containing "value"

unsigned int LinkedList::Search(double value) {
    return data*;
}


// Delete the node at position "index", return the value that was there

double LinkedList::DeleteNode(unsigned int index) {
    Node* cur = *head;
    if (index == *head) {
        *head = cur->next;
        delete index;
        return true;
    }

    while (cur) {
        if (cur->next == value) {
            cur->next = value->next;
            delete value;
            return true;
        }
        cur = cur->next;
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
    struct Node* reverse(struct Node** head)
    {
        Node* parent = *head;
        Node* me = parent->next;
        Node* child = me->next;

        parent->next = NULL;
        while (child) {
            me->next = parent;
            parent = me;
            me = child;
            child = child->next;
        }
        me->next = parent;
        *head = me;
        return *head;
    }
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
