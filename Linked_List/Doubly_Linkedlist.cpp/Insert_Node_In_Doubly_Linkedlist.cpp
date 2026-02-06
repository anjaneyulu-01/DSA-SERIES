/*
Insert node before head in Doubly Linked List
Given the head of a doubly linked list and an integer X, insert a node with value X before the head of the linked list and return the head of the modified list.


Example 1

Input: head = [1, 2, 3], X = 3

Output: head = [3, 1, 2, 3]

Explanation: 3 was added before the 1st node. Note that the head's value is changed.

Example 2

Input: head = [5], X = 7

Output: head = [7, 5]

Now your turn!

Input: head = [2, 3], X = 10

Output:

Pick your answer


10 -> head <-> 2 <-> 3

head -> 2 <-> 10 <-> 3

head -> 10 <-> 2 <-> 3

head -> 2 <-> 3 <-> 10
Constraints

n == Number of nodes in the Linked List
1 <= n <= 100
0 <= ListNode.val <= 100
0 <= X <= 100
*/

#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* prev;
Node* next;

Node(int val){
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
void insertEnd(int val){
    Node* newNode = new Node(val);
    if(!head){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void insertBeforeHead(int X){
    Node* newNode = new Node(X);
    if(!head){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void display(){
    Node* temp = head;
    while(temp){
        cout << temp->data;
        if(temp->next)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}
};

int main(){
DoublyLinkedList dll;
dll.insertEnd(2);
dll.insertEnd(3);
int X=10;
dll.insertBeforeHead(X);
cout << "Modified Doubly Linked List:\n";
dll.display();

return 0;
}
