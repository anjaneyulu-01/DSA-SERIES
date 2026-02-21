/*
Add one to a number represented by LL
Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.



The number will contain no leading zeroes except when the value represented is zero itself.


Example 1

Input: head -> 1 -> 2 -> 3

Output: head -> 1 -> 2 -> 4

Explanation: The number represented by the linked list = 123.

123 + 1 = 124.

Example 2

Input: head -> 9 -> 9

Output: head -> 1 -> 0 -> 0

Explanation: The number represented by the linked list = 99.

99 + 1 = 100.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
public:
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    Node* addOne(Node* head){
        
        head = reverse(head);
      Node* temp = head;
        int carry = 1;

        while(temp != NULL){
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;

            if(carry == 0) break;

            if(temp->next == NULL && carry > 0){
                temp->next = new Node(carry);
                carry = 0;
                break;
            }

            temp = temp->next;
        }

        head = reverse(head);
        return head;
    }
};

void printList(Node* head){
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
   cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.addOne(head);

    cout << "After Adding One: ";
    printList(head);

    return 0;
}