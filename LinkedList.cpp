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

//One Method
public class Node {
	Node* next; //Takes a next value
	int data; //Declaring some data
	public Node(int data) {
		this.data = data;  //Constructor for making the data
	}

	public class LinkedList {
		Node head;

		public void append(int data) {
			if (head == null) {
				head = new Node(data);
				return;
			}
		}
		Node current = head; //Node: current = this ->data
		while (current.next != null) {
			current = current.next;
		}
		current.next = new Node(data);
	}

	public void prepend(int data) {
		Node newHead = new Node(data);
		newHead.next = head;
		head = newHead;
	}

	public void deleteWithValue(int data) {
		if (head == null) return; //If the head is null return
		if (head.data == data) {  //Head is equal to the next value
			head = head.next;
			return;
		}

		Node current = head;  //Starting at head
		while (current.next != null) {	//Going through the linked list
			if (current.next.data == data) { 
				current.next = current.next.next; //Basically skip over the one you want to delete
				return;
			}
			current = current.next;
		}
	}
	//---------------------------------------
	
};
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


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
