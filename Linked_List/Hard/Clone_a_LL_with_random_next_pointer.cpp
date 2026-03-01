/*
Clone a LL with random and next pointer
Given the head of a special linked list of n nodes where each node contains an additional pointer called 'random' which can point to any node in the list or null.



Construct a deep copy of the linked list where,

n new nodes are created with corresponding values as original linked list.
The random pointers point to the corresponding new nodes as per their arrangement in the original list.
Return the head of the newly constructed linked list.


Note: For custom input, a n x 2 matrix is taken with each row having 2 values:[ val, random_index] where,

val: an integer representing ListNode.val
random_index: index of the node (0 - n-1) that the random pointer points to, otherwise -1.

Example 1

Input: [[1, -1], [2, 0], [3, 4], [4, 1], [5, 2]]

Output: 1 2 3 4 5, true

Explanation: All the nodes in the new list have same corresponding values as original nodes.

All the random pointers point to their corresponding nodes in the new list.

'true' represents that the nodes and references were created new.

Example 2

Input: [[5, -1], [3, -1], [2, 1], [1, 1]]

Output: 5 3 2 1, true

Explanation: All the nodes in the new list have same corresponding values as original nodes.

All the random pointers point to their corresponding nodes in the new list.

'true' represents that the nodes and references were created new.

[[5, -1], [3, -1], [2, -1], [1, -1]] will be incorrect, although it has the same values.

give the answer with the mian function and with classes and objects and with one input from above
*/


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int val){
        data = val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
public:
    Node* cloneLL(Node* head){
        if(head == NULL) return NULL;

        Node* temp = head;
        while(temp != NULL){
            Node* newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->random != NULL)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* original = head;
        Node* copy = head->next;
        Node* copyHead = head->next;

        while(original != NULL){
            original->next = original->next->next;
            if(copy->next != NULL)
                copy->next = copy->next->next;

            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};

void printList(Node* head){
    while(head != NULL){
        cout<<head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n1->random = NULL; 
    n2->random = n1;  
    n3->random = n5;  
    n4->random = n2;  
    n5->random = n3;     

    Solution obj;
    Node* clonedHead = obj.cloneLL(n1);

    cout << "Original List: ";
    printList(n1);

    cout << "Cloned List: ";
    printList(clonedHead);

    return 0;
}