/*
Delete all occurrences of a key in DLL
Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.


Example 1

Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1

Output: head -> 2 <-> 3 <-> 4

Explanation: All nodes with the value 1 were removed.

Example 2

Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2

Output: head -> 3 <-> -1 <-> 4

Explanation: All nodes with the value 2 were removed.

Note that the value of head is changed.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
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
    void deleteAll(int target){
        Node* temp = head;

        while (temp != NULL){

            if(temp->data == target){

                Node* nodeToDelete = temp;
                if(temp == head){
                    head = temp->next;
                    if (head != NULL)
                        head->prev = NULL;
                }
                else{
                    temp->prev->next = temp->next;

                    if(temp->next != NULL)
                        temp->next->prev = temp->prev;
                }

                temp = temp->next;
                delete nodeToDelete;
            }
            else{
                temp = temp->next;
            }
        }
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data;
            if(temp->next != NULL)
                cout << " <-> ";
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
    dll.insert(1);
    dll.insert(4);

    int target = 1;

    cout << "Original List: ";
    dll.print();

    dll.deleteAll(target);

    cout << "After Deleting " << target << ": ";
    dll.print();

    return 0;
}