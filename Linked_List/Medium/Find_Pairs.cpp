/*
Find Pairs with Given Sum in Doubly Linked List
Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.



Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.


Example 1

Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7

Output: [[1, 6], [2, 5]]

Explanation:

1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.

Example 2

Input: head = [1, 5, 6], target = 6

Output: [[1, 5]]

Explanation:

1 + 5 = 6 is the only valid pair.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution{
public:

    vector<vector<int>> findPairs(Node* head, int target){
        vector<vector<int>> result;

        if(head == NULL) return result;

        Node* left = head;
        Node* right = head;
        while(right->next != NULL){
            right = right->next;
        }
        while(left != NULL && right != NULL && left != right && right->next != left){
            int sum = left->data + right->data;

            if(sum == target){
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(sum < target){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }

        return result;
    }
};

Node* insert(Node* head, int val){
    Node* newNode = new Node(val);

    if(head == NULL)
        return newNode;

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

int main(){

    Node* head = NULL;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 8);
    head = insert(head, 9);

    int target = 7;

    Solution obj;

    vector<vector<int>> pairs = obj.findPairs(head, target);

    cout << "Pairs with sum " << target << " are:\n";

    for(auto pair : pairs){
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }

    return 0;
}