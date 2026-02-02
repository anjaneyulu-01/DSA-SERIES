/*
Insertion at the head of Linked List
Given the head of a singly linked list and an integer X, insert a node with value X at the head of the linked list and return the head of the modified list.


Example 1

Input: linkedList = [1, 2, 3], X = 7

Output: [7, 1, 2, 3]

Explanation:

7 was added as the 1st node.

Example 2

Input: linkedList = [], X = 7

Output: [7]

Explanation:

7 was added as the 1st node.
*/

#include <iostream>
#include <vector>
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
Node* insertAtHead(Node* head, int X){
Node* newNode = new Node(X);
newNode->next = head;
head = newNode;
return head;
}
Node* createLinkedList(vector<int> arr){

Node* head = NULL;
Node* tail = NULL;
for(int val : arr){
  Node* newNode = new Node(val);
  if(head == NULL){
      head = newNode;
      tail = newNode;
  }
  else{
      tail->next = newNode;
      tail = newNode;
  }
}

return head;
}
void printLinkedList(Node* head){
Node* temp = head;
while(temp != NULL){
    cout << temp->data;
    if(temp->next != NULL) cout << " -> ";
    temp = temp->next;
}
cout << endl;
}

int main(){
vector<int> list1 = {1, 2, 3};
int X1 = 7;
Node* head1 = createLinkedList(list1);
cout << "Example 1 Original List: ";
printLinkedList(head1);
head1 = insertAtHead(head1, X1);
cout << "After Inserting " << X1 << " at Head: ";
printLinkedList(head1);
 return 0;
}
