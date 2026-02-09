/*
Find Middle of Linked List
Given the head of a singly Linked List, return the middle node of the Linked List.



If the Linked List has an even number of nodes, return the second middle one.


Example 1

Input: head -> 3 -> 8 -> 7 -> 1 -> 3

Output(value at returned node): 7

Explanation: There are 5 nodes, so the middle node is the 3rd Node, with value 7.

Example 2

Input: head -> 2 -> 9 -> 1 -> 4 -> 0 -> 4

Output(value at returned node): 4

Explanation: There are 6 nodes, thus both the 3rd and 4th nodes are middle. So the 2nd middle node (4th Node) is returned with value 4.
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
        if(head == NULL){
            head = new Node(val);
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
    Node* findMiddle(){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main(){
    LinkedList list;
    list.insert(2);
    list.insert(9);
    list.insert(1);
    list.insert(4);
    list.insert(0);
    list.insert(4);

    cout << "Linked List: ";
    list.display();

    Node* middle = list.findMiddle();
    cout << "Middle Node Value: " << middle->data << endl;

    return 0;
}
