/*
Find the length of the Linked List
You are given the head of a singly linked list. Your task is to return the number of nodes in the linked list.


Example 1

Input: head = [1, 2, 3, 4, 5]

Output: 5

Example 2

Input: head = [8, 6]

Output: 2

*/

#include <iostream>
using namespace std;
struct ListNode{
int val;
ListNode* next;
ListNode(int x){
    val = x;
    next = NULL;
}
};
int getLength(ListNode* head){
    int count = 0;
  while(head != NULL){
        count++;
        head = head->next;
    }
  return count;
}

int main(){
ListNode* head=new ListNode(1);
head->next=new ListNode(2);
head->next->next=new ListNode(3);
head->next->next->next=new ListNode(4);
head->next->next->next->next=new ListNode(5);

cout << "Length of list : " << getLength(head) << endl;
return 0;
}
