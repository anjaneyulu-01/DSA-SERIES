/*
Find the intersection point of Y LL
Given the heads of two linked lists A and B, containing positive integers. Find the node at which the two linked lists intersect. If they do intersect, return the node at which the intersection begins, otherwise return null.



The Linked List will not contain any cycles. The linked lists must retain their original structure, given as per the input, after the function returns.



Note: for custom input, the following parameters are required(your program is not provided with these parameters):

intersectVal - The value of the node where the intersection occurs. This is -1 if there is no intersected node.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node(-1 if no intersection).
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node(-1 if no intersection).
listA - The first linked list.
listB - The second linked list.

Example 1

Input: listA: intersectVal = 4, skipA = 3, skipB = 2, head -> 1 -> 2 -> 3 -> 4 -> 5, listB: head -> 7 -> 8 -> 4 -> 5



Output(value at returned node is displayed): 4

Explanation: The two lists have nodes with values 4 and 5 as their tails.

Example 2

Input: listA: intersectVal = -1, skipA = -1, skipB = -1, head -> 1 -> 2 -> 3, listB: head -> 8 -> 9



Output(value at returned node is displayed): null

Explanation: The two lists do not intersect.
*/

#include <bits/stdc++.h>
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
    Node* getIntersectionNode(Node* headA, Node* headB) {
        if (!headA || !headB) return NULL;

        Node* a = headA;
        Node* b = headB;

        while (a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};

int main() {
    Node* common1 = new Node(4);
    Node* common2 = new Node(5);
    common1->next = common2;

    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = common1;

    Node* headB = new Node(7);
    headB->next = new Node(8);
    headB->next->next = common1;

    Solution obj;
    Node* intersection = obj.getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}