/*
Remove duplicated from sorted DLL
Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.



Return the head of the modified linked list.


Example 1

Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

Output: head -> 1 <-> 3 <-> 4 <-> 5

Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

The underlined nodes were deleted to get the desired result.

Example 2

Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

Output: head -> 1 <-> 2

Explanation: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

The underlined nodes were deleted to get the desired result.
*/

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
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
    void removeDuplicates(){
        if(head == NULL) return;

        Node* current = head;

        while(current != NULL && current->next != NULL){
            if(current->data == current->next->data){

                Node* duplicate = current->next;
                current->next = duplicate->next;

                if(duplicate->next != NULL){
                    duplicate->next->prev = current;
                }

                delete duplicate;
            }
            else{
                current = current->next;
            }
        }
    }

    void print(){
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    DoublyLinkedList dll;

    dll.insert(1);
    dll.insert(1);
    dll.insert(3);
    dll.insert(3);
    dll.insert(4);
    dll.insert(5);

    cout << "Original List: ";
    dll.print();

    dll.removeDuplicates();

    cout << "After Removing Duplicates: ";
    dll.print();

    return 0;
}