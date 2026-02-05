/*
Search in Linked List
You are given the head of a singly linked list and an integer key.

Return true if the key exists in the linked list, otherwise return false.


Example 1

Input: head = [1, 2, 3, 4], key = 3

Output: true

Explanation: The linked list is 1 → 2 → 3 → 4. The key 3 is present in the list.

Example 2

Input: head = [7, 8, 9, 10, 11], key = 5

Output: false

Explanation: The key 5 is not present in the list.
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
private:
Node* head;

public:
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
bool search(int key){
    Node* temp = head;
while(temp != NULL){
        if (temp->data == key)
            return true;
        temp = temp->next;
    }

    return false;
}
void display(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
};

int main(){
LinkedList list1;
list1.insert(1);
list1.insert(2);
list1.insert(3);
list1.insert(4);

int key1 = 3;

cout << "List 1: ";
list1.display();

cout << "Search 3: ";
cout << (list1.search(key1) ? "true" : "false") << endl;
return 0;
}

