/*
Length of loop in LL
Given the head of a singly linked list, find the length of the loop in the linked list if it exists. Return the length of the loop if it exists; otherwise, return 0.



A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.



Note that pos is not passed as a parameter.


Example 1



Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1

Output: 4

Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.

Example 2



Input: head -> 1 -> 3 -> 7 -> 4, pos = -1

Output: 0

Explanation: No loop is present in the linked list.
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
int lengthOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){ 
            int count = 1;
            Node* temp = slow->next;
            
            while(temp != slow){
                count++;
                temp = temp->next;
            }
            
            return count;
        }
    }
    
    return 0; 
}
};
void createLoop(Node* head, int pos){
if(pos == -1) return;

Node* loopNode = NULL;
Node* temp = head;
int index = 0;

while(temp->next != NULL){
    if(index == pos)
        loopNode = temp;
    temp = temp->next;
    index++;
}

temp->next = loopNode;
}

int main(){

Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);

int pos = 1; 
createLoop(head, pos);
Solution obj;
int result = obj.lengthOfLoop(head);

cout << "Length of loop: " << result << endl;

return 0;
}
