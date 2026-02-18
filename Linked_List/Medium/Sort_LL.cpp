/*
Sort LL
Given the head of a singly linked list. Sort the values of the linked list in non-decreasing order and return the head of the modified linked list.


Example 1

Input: head -> 5 -> 6 -> 1 -> 2 -> 1

Output: head -> 1 -> 1 -> 2 -> 5 -> 6

Explanation: 1 <= 1 <= 2 <= 5 <= 6

Example 2

Input: head -> 6 -> 5 -> -1 -> -2 -> -3

Output: head -> -3 -> -2 -> -1 -> 5 -> 6

Explanation: -3 <= -2 <= -1 <= 5 <= 6
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

class LinkedList{
public:
Node* head;

LinkedList(){
    head = NULL;
}
void insert(int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void print(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* merge(Node* left, Node* right){
    if(!left) return right;
    if(!right) return left;

    if(left->data <= right->data){
        left->next = merge(left->next, right);
        return left;
    }
    else{
        right->next = merge(left, right->next);
        return right;
    }
}
Node* getMiddle(Node* head){
    if(!head) return head;

    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node* mergeSort(Node* head){
    if (!head || !head->next)
        return head;

    Node* mid = getMiddle(head);
    Node* rightHead = mid->next;
    mid->next = NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}
void sortList(){
    head = mergeSort(head);
}
};


int main(){
LinkedList list;

list.insert(5);
list.insert(6);
list.insert(1);
list.insert(2);
list.insert(1);

cout << "Original List: ";
list.print();

list.sortList();

cout << "Sorted List: ";
list.print();

return 0;
}
