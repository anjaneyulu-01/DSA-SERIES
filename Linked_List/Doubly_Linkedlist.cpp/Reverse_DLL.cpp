/*
Reverse a Doubly Linked List
You are given the head of a doubly linked list.



Reverse the list in-place and return the new head of the reversed list.


Example 1

Input: head = [10, 20, 30]

Output:﻿ [30, 20, 10]

Example 2

Input: head = [1, 3, 5, 7, 9]

Output: [9, 7, 5, 3, 1]
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
class DoublyLinkedList{
public:
    Node* head;

    DoublyLinkedList(){
        head = NULL;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    void reverse(){
        Node* curr = head;
        Node* temp = NULL;

        while(curr != NULL){
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if(temp != NULL)
            head = temp->prev;
    }
    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    DoublyLinkedList dll1;
    dll1.insert(10);
    dll1.insert(20);
    dll1.insert(30);

    cout << "Original List 1: ";
    dll1.printList();

    dll1.reverse();

    cout << "Reversed List 1: ";
    dll1.printList();

    cout << endl;
    return 0;
}
