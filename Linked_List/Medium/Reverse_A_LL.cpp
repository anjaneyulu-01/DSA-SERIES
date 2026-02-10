/*
Reverse a LL
Given the head of a singly linked list. Reverse the given linked list and return the head of the modified list.


Example 1

Input: head -> 1 -> 2 -> 3 -> 4 -> 5

Output: head -> 5 -> 4 -> 3 -> 2 -> 1

Explanation: All the links are reversed and the head now points to the last node of the original list.

Example 2

Input: head -> 6 -> 8

Output: head -> 8 -> 6

Explanation: All the links are reversed and the head now points to the last node of the original list.

This can be seen like: 6 <- 8 <- head.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }
    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;   
            prev = curr;          
            curr = nextNode;       
        }
        head = prev; 
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);

    cout << "Original Linked List:\n";
    ll.display();

    ll.reverse();

    cout << "Reversed Linked List:\n";
    ll.display();

    return 0;
}
