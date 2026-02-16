/*
Remove Nth node from the back of the LL

Given the head of a singly linked list and an integer n. Remove the nth node from the back of the linked List and return the head of the modified list. The value of n will always be less than or equal to the number of nodes in the linked list.


Example 1

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, n = 2

Output: head -> 1 -> 2 -> 3 -> 5

Explanation: The 2nd node from the back was the node with value 4.

Example 2

Input: head -> 5 -> 4 -> 3 -> 2 -> 1, n = 5

Output: head -> 4 -> 3 -> 2 -> 1

Explanation: The 5th node from the back is the first node.
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

    LinkedList(){
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
    void removeNthFromEnd(int n) {
        Node* dummy = new Node(0);
        dummy->next = head;

        Node* fast = dummy;
        Node* slow = dummy;

        for(int i = 0; i < n; i++)
            fast = fast->next;

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        Node* del = slow->next;
        slow->next = del->next;
        delete del;

        head = dummy->next;
        delete dummy;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {

    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    int n = 2;

    cout << "Original List:\n";
    list.print();

    list.removeNthFromEnd(n);

    cout << "\nAfter Removing " << n << "th Node From End:\n";
    list.print();

    return 0;
}
