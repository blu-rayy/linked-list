#include<iostream>
#include "data.h"
#include <cctype>   
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

void LinkedList:: insertAtBeginning(int val) {
    	Node *newNode = new Node;
    	newNode->data = val;
    	newNode->next = head;
	
    	head = newNode;
    }

void LinkedList:: insertAfter(int val,int pos) {
    Node* temp = head;
	if(pos > 10){
		size = 10;
	}
	
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
bool LinkedList::search(int val) {
    Node *ptr = head;

    while (ptr != NULL){
		if (ptr->data == val){
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

// Returns the number of elements in the list
int LinkedList::getSize(){
	int size = 0;
	Node *ptr = head;
	
	while (ptr != NULL){
		size++;
		ptr = ptr->next;
	}

    return size;
}

// Returns true if the list is empty, otherwise returns false
bool LinkedList::isEmpty() {
    return head == NULL;
}

// Returns true if the list is full, otherwise returns false
bool LinkedList::isFull() {
    return size >=10;
}

// Displays the elementsin the list
void LinkedList::printList() {
    Node* ptr = head;

    while(ptr != NULL){

	cout<< ptr->data;
	ptr = ptr->next;
    }
	cout<<endl;
};
