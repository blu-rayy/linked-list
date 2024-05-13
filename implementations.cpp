#include<iostream>
#include "data.h"
using namespace std;


    void LinkedList::insertAtBeginning(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void LinkedList::insertAfter(int val, int pos) {
        if (pos > size + 1) {
            cout << "Position out of range." << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node;
        newNode->data = val;
        if (temp == NULL) { // If position is at the end of the list
            newNode->next = NULL;
            Node* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void LinkedList::insert(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Removes the element at a specified location from a non-empty list
    void LinkedList::removeAt(int pos) {
        if (pos < 1 || pos > size) {
            cout << "Position out of range." << endl;
            return;
        }
        Node* temp1 = head;
        if (pos == 1) {
            head = temp1->next;
            delete temp1;
            size--;
            return;
        }
        for (int i = 1; i < pos - 1; i++) {
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        size--;
    }

    // Searches for an element in the list
    bool LinkedList::search(int val) {
        Node* ptr = head;
        while (ptr != NULL) {
            if (ptr->data == val) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    // Returns the number of elements in the list
    int LinkedList::getSize() {

        int count = 0;
        Node *ptr = head;
        
        while (ptr != NULL){
            count++;
            ptr = ptr->next;
        }

        return count;
    }

    // Returns true if the list is empty, otherwise returns false
    bool LinkedList::isEmpty() {
        return head == NULL;
    }

    // Returns true if the list is full, otherwise returns false
    bool LinkedList::isFull() {
        return size == 10;
    }

    // Displays the elements in the list
    void LinkedList::printList() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
