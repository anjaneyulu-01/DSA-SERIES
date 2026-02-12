/*
Find the starting point in LL
Given the head of a singly linked list, the task is to find the starting point of a loop in the linked list if it exists. Return the starting node if a loop exists; otherwise, return null.



A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos denotes the index (0-based) of the node from where the loop starts.



Note that pos is not passed as a parameter.


Example 1



Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1

Output(value of the returned node is displayed): 2

Expla﻿nation: The tail of the linked list connects to the node at 1st index.

Example 2



Input: head -> 1 -> 3 -> 7 -> 4, pos = -1

Output(value of the returned node is displayed): null

Explanation: No loop is present in the linked list.
*/

#include <iostream>
using namespace std;

class Node{
public:
int data;
Node* next;

Node(int x){
    data = x;
    next = NULL;
}
};

class Solution{
public:
Node* detectCycle(Node* head){
    if(!head) return NULL;

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
          if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}
};

int main(){
Node* head=new Node(6);
Node* second=new Node(3);
Node* third=new Node(7);
head->next=second;
second->next=third;
third->next=head;  

Solution obj;
Node* result=obj.detectCycle(head);

if(result != NULL)
    cout << "Starting point of loop: " << result->data << endl;
else
    cout << "No loop found" << endl;

return 0;
}
