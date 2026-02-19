/*
Sort a Linked List of 0's 1's and 2's
Given the head of a singly linked list consisting of only 0, 1 or 2.



Sort the given linked list and return the head of the modified list.



Do it in-place by changing the links between the nodes without creating new nodes.


Example 1

Input: linkedList = [1, 0, 2, 0 , 1]

Output: [0, 0, 1, 1, 2]

Explanation: The values after sorting are [0, 0, 1, 1, 2].

Example 2

Input: linkedList = [1, 1, 1, 0]

Output: [0, 1, 1, 1]

Explanation: The values after sorting are [0, 1, 1, 1].
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

class Solution {
public:
    Node* sortList(Node* head) {

        if (head == NULL || head->next == NULL)
            return head;

        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;

        Node* curr = head;

        while(curr != NULL){

            if(curr->data == 0){
                zero->next = curr;
                zero = zero->next;
            }
            else if(curr->data == 1){
                one->next = curr;
                one = one->next;
            }
            else{
                two->next = curr;
                two = two->next;
            }

            curr = curr->next;
        }
        zero->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;
        Node* newHead = zeroHead->next;

        return newHead;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(1);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
