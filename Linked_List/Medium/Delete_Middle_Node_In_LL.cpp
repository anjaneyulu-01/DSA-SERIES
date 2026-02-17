/*
Delete the middle node in LL

Given the head of a non-empty singly linked list containing integers, delete the middle node of the linked list. Return the head of the modified linked list.



The middle node of a linked list of size n is the (⌊n / 2⌋ + 1)th node from the start using 1-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.


Example 1

Input: head -> 1 -> 2 -> 3 -> 4 -> 5

Output: head -> 1 -> 2 -> 4 -> 5

Explanation: n = 5.

⌊n / 2⌋ + 1 = 3, therefore middle node has index 3 and so the node with value 3 was deleted.

Example 2

Input: head -> 7 -> 6 -> 5 -> 4

Output: head -> 7 -> 6 -> 4

Expl﻿anation: n = 4.

⌊n / 2⌋ + 1 = 3, therefore middle node has index 3 and so the node with value 5 was deleted.

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void insert(int val){
        Node* newNode = new Node(val);

        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteMiddle(){

        if(!head || !head->next){
            head = NULL;
            return;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->data;
            if(temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

    LinkedList list;
    int arr[] = {1,2,3,4,5};
    int n = 5;

    for(int i=0;i<n;i++)
        list.insert(arr[i]);

    cout << "Original List:\n";
    list.display();

    list.deleteMiddle();

    cout << "After deleting middle:\n";
    list.display();

    return 0;
}
