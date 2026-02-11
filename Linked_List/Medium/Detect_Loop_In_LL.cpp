/*
Detect a loop in LL
Subscribe to TUF+

Hints
Company
Given the head of a singly linked list. Return true if a loop exists in the linked list or return false.



A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer.



Internally, pos is used to denote the index(0-based) of the node from where the loop starts. Note that pos is not passed as a parameter.


Example 1
Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1

Output: true

Explanation: The tail of the linked list connects to the node at 1st index.

Example 2

Input: head -> 1 -> 3 -> 7 -> 4, pos = -1

Output: false

Explanation: No loop is present in the linked list.
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
class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void insert(int val){
        Node* newNode = new Node(val);

        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }
    void createLoop(int pos){
        if(pos < 0) return;

        Node* loopNode = NULL;
        Node* temp = head;
        int index = 0;

        while(temp->next){
            if(index == pos)
                loopNode = temp;
            temp = temp->next;
            index++;
        }

        temp->next = loopNode;
    }
    bool detectLoop(){
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }
        return false;
    }
};

int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.createLoop(1);

    if(ll.detectLoop())
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
