/*
Add two numbers in Linked List
Given two non-empty linked lists linkedList1 and linkedList2 which represent two non-negative integers.



The digits are stored in reverse order with each node storing one digit.

Add two numbers and return the sum as a linked list.



The sum Linked List will be in reverse order as well.


The Two given Linked Lists represent numbers without any leading zeros, except when the number is zero itself.

Example 1

Input: linkedList1 = [5, 4], linkedList2 = [4]

Output: [9, 4]

Explanation: linkedList1 = 45, linkedList2 = 4.

linkedList1 + linkedList2 = 45 + 4 = 49.

Example 2

Input: linkedList1 = [4, 5, 6], linkedList2 = [1, 2, 3]

Output: [5, 7, 9]

Explanation: linkedList1 = 654, linkedList2 = 321.

linkedList1 + linkedList2 = 654 + 321 = 975.
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

class Solution{
public:
    Node* addTwoNumbers(Node* l1, Node* l2){
        
        Node* dummy = new Node(0);
        Node* current = dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry){
            
            int sum = carry;

            if (l1 != NULL){
                sum += l1->data;
                l1 = l1->next;
            }

            if (l2 != NULL){
                sum += l2->data;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new Node(sum % 10);
            current = current->next;
        }

        return dummy->next;
    }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data;
        if(head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* linkedList1 = new Node(5);
    linkedList1->next = new Node(4);

    Node* linkedList2 = new Node(4);

    Solution obj;
    Node* result = obj.addTwoNumbers(linkedList1, linkedList2);

    cout << "Result: ";
    printList(result);

    return 0;
}