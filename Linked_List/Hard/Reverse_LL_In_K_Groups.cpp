/*
Reverse LL in group of given size K
Given the head of a singly linked list containing integers, reverse the nodes of the list in groups of k and return the head of the modified list. If the number of nodes is not a multiple of k, then the remaining nodes at the end should be kept as is and not reversed.



Do not change the values of the nodes, only change the links between nodes.


Example 1

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2

Output: head -> 2 -> 1 -> 4 -> 3 -> 5

Explanation: The groups 1 -> 2 and 3 -> 4 were reversed as 2 -> 1 and 4 -> 3.

Example 2

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, k = 3

Output: head -> 3 -> 2 -> 1 -> 4 -> 5

Explanation: The groups 1 -> 2 -> 3 were reversed as 3 -> 2 -> 1.

Note that 4 -> 5 was not reversed.

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

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node* reverseKGroup(Node* head, int k) {

        Node* temp = head;
        int count = 0;

        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k)
            return head;
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
            head->next = reverseKGroup(next, k);

        return prev; 
    }
    void display(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {

    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    int k = 2;

    cout << "Original List: ";
    list.display(list.head);

    list.head = list.reverseKGroup(list.head, k);

    cout << "Reversed in groups of " << k << ": ";
    list.display(list.head);

    return 0;
}