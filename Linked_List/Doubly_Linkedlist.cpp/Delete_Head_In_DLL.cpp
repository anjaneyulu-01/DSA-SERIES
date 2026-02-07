/*
Delete head of Doubly Linked List
Given the head of a doubly linked list, remove the node at the head of the linked list and return the head of the modified list.



The head is the first node of the linked list.


Example 1

Input: doublyLinkedList = [1, 2, 3]

Output: [2, 3]

Explanation:

The node with value 1 was removed.
Example 2

Input: doublyLinkedList = [7]

Output: [ ]

Explanation:

Note that the head has null value after the removal.
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
        newNode->prev = temp;
    }
    void deleteHead(){
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;
    if(head != NULL)
            head->prev = NULL;

        delete temp;
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
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
   cout << "Original List: ";
    dll.display();
    dll.deleteHead();

    cout << "After Deleting Head: ";
    dll.display();

    return 0;
}
