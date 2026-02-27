/*
Rotate a LL
Given the head of a singly linked list containing integers, shift the elements of the linked list to the right by k places and return the head of the modified list. Do not change the values of the nodes, only change the links between nodes.


Example 1

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2

Output: head -> 4 -> 5 -> 1 -> 2 -> 3

Explanation:

List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.

List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

Example 2

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 4

Output: head -> 2 -> 3 -> 4 -> 5 -> 1

Explanation:

List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.

List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

List after 3 shift to right: head -> 3 -> 4 -> 5 -> 1 -> 2.

List after 4 shift to right: head -> 2 -> 3 -> 4 -> 5 -> 1.
*/
#include <iostream>
using namespace std;

class Node{
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
    Node* rotateRight(Node* head, int k){
        if(!head || !head->next || k == 0)
            return head;

        Node* temp = head;
        int length = 1;
        while(temp->next != NULL){
            temp = temp->next;
            length++;
        }
        temp->next = head;
        k = k % length;
        int stepsToNewTail = length - k;
        Node* newTail = head;

        for(int i = 1; i < stepsToNewTail; i++){
            newTail = newTail->next;
        }
        Node* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
    void display(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    int k = 2;

    cout << "Original List: ";
    list.display(list.head);

    list.head = list.rotateRight(list.head, k);

    cout << "After Rotating Right by " << k << " places: ";
    list.display(list.head);

    return 0;
}