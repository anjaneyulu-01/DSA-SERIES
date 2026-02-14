/*
Check if LL is palindrome or not
Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. Check whether the linked list values form a palindrome or not. Return true if it forms a palindrome, otherwise, return false.



A palindrome is a sequence that reads the same forward and backwards.


Example 1

Input: head -> 3 -> 7 -> 5 -> 7 -> 3

Output: true

Explanation: 37573 is a palindrome.

Example 2

Input: head -> 1 -> 1 -> 2 -> 1

Output: false

Explanation: 1121 is not a palindrome.
*/

#include <iostream>
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

class Solution{
public:
    Node* reverse(Node* head) {
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
    bool isPalindrome(Node* head){
        if (head == NULL || head->next == NULL)
            return true;

        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* secondHalf = reverse(slow->next);

        Node* firstHalf = head;
        while (secondHalf != NULL){
            if (firstHalf->data != secondHalf->data)
                return false;

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};

int main(){
    Node* head = new Node(3);
    head->next = new Node(7);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(3);

    Solution obj;

    if(obj.isPalindrome(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
