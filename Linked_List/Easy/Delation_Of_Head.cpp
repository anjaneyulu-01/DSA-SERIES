/*
Deletion of the head of LL
Given the head of a singly linked list, delete the head of the linked list and return the head of the modified list. The head is the first node of the linked list.



Note : Please note that this section might seem a bit difficult without prior knowledge on what linkedList is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!


Example 1

Input: linkedList = [1, 2, 3]

Output: [2, 3]

Explanation:

The first node was removed.

Example 2

Input: linkedList = [1]

Output: []

Explanation:

Note that the head of the linked list gets changed.
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
Node* deleteHead(Node* head){
    if(head == NULL)
        return NULL;

    Node* temp = head;
    head = head->next;
    delete temp;
   return head;
}
void printList(Node* head){
while(head != NULL){
    cout << head->data;
    if(head->next != NULL)
        cout << " -> ";
    head = head->next;
}
cout << endl;
}

int main() {
cout << "Example 1:" << endl;
Node* head1 = new Node(1);
head1->next = new Node(2);
head1->next->next = new Node(3);
cout << "Original List: ";
printList(head1);
head1 = deleteHead(head1);

cout << "After Deleting Head: ";
printList(head1);
return 0;
}
