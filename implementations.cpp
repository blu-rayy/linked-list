#include<iostream>
#include "data.h"
using namespace std;

void LinkedList:: insertAtBeginning(int val) {
    	Node *newNode = new Node;
    	newNode->data = val;
    	newNode->next = head;
    	
    	head = newNode;
    }

void LinkedList:: insertAfter(int val,int pos) {
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            return;
        }
        temp = temp->next;
    }
    Node* newNode = new Node;
    newNode->data = val;
    if(temp == NULL) { // If position is at the end of the list
        newNode->next = NULL;
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void LinkedList:: insert(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
}

// Removes the element at a specified location from a non-empty list
void LinkedList::removeAt(int pos) {
    Node* temp1 = head;
    if (pos == 1) {
        head = temp1->next;
        delete temp1;
        return;
    }
    for (int i = 1; i < pos - 1; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

// Searches for an element in the list
<<<<<<< HEAD
bool search(int val) {
    Node *ptr = head;
    
    while (ptr != NULL){
		if (ptr->data == val){
			return true;
		}
		ptr = ptr->next;
	}
	return false;
=======
bool LinkedList::search(int val) {
    //TODO
>>>>>>> 09a721f9d3710ad2cf3c550f30a98c0b090ea4eb
}

// Returns the number of elements in the list
int LinkedList::getSize(){
	int size = 0;
	Node *ptr = head;
	
	while (ptr != NULL){
		size++;
		ptr = ptr->next;
	}
<<<<<<< HEAD
=======

    return size;
>>>>>>> 09a721f9d3710ad2cf3c550f30a98c0b090ea4eb
}

// Returns true if the list is empty, otherwise returns false
bool LinkedList::isEmpty() {
    return head == NULL;
}

// Returns true if the list is full, otherwise returns false
<<<<<<< HEAD
bool isFull() {
    
}

// Displays the elements in the list
void printList() {
    
=======
bool LinkedList::isFull() {
    //TODO
}

// Displays the elements in the list
void LinkedList::printList() {
    //TODO
>>>>>>> 09a721f9d3710ad2cf3c550f30a98c0b090ea4eb
};
