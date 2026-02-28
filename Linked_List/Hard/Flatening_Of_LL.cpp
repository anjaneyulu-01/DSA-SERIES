/*
Flattening of LL
Given a special linked list containing n head nodes where every node in the linked list contains two pointers:

‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head
Each of these child linked lists is in sorted order and connected by a 'child' pointer.



Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer and return the head of the modified list.


Example 1

Input:



Output: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12

Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

Example 2

Input:



Output: head -> 2 -> 4 -> 5 -> 10 -> 12 -> 13 -> 16 -> 17 -> 20

Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.
*/

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* child;

    Node(int val){
        data = val;
        next = NULL;
        child = NULL;
    }
};

class LinkedList{
public:

    Node* merge(Node* a, Node* b){
        if (!a) return b;
        if (!b) return a;

        Node* result;

        if(a->data < b->data){
            result = a;
            result->child = merge(a->child, b);
        }
        else{
            result = b;
            result->child = merge(a, b->child);
        }

        result->next = NULL;
        return result;
    }
    Node* flatten(Node* head){
        if(!head || !head->next)
            return head;

        head->next = flatten(head->next);

        head = merge(head, head->next);

        return head;
    }
    void printList(Node* head){
        while(head){
            cout << head->data << " ";
            head = head->child;
        }
        cout << endl;
    }
};

int main() {

    LinkedList list;
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(7);
    head->next->next->next = new Node(10);
    head->child = new Node(2);
    head->child->child = new Node(3);

    head->next->child = new Node(5);
    head->next->child->child = new Node(6);
    head->next->next->child = new Node(8);
    head->next->next->child->child = new Node(9);
    head->next->next->next->child = new Node(11);
    head->next->next->next->child->child = new Node(12);

    cout << "Flattened List:\n";

    Node* flatHead = list.flatten(head);
    list.printList(flatHead);

    return 0;
}