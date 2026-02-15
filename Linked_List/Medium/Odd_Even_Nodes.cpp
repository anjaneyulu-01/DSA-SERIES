/*
Segregate odd and even nodes in Linked List

Given the head of a singly linked list. Group all the nodes with odd indices followed by all the nodes with even indices and return the reordered list.



Consider the 1st node to have index 1 and so on. The relative order of the elements inside the odd and even group must remain the same as the given input.


Example 1

Input: linkedList = [1, 2, 3, 4, 5]

Output: [1, 3, 5, 2, 4]

Explanation:

The nodes with odd indices are 1, 3, 5 and the ones with even indices are 2, 4.

Example 2

Input: linkedList = [4, 3, 2, 1]

Output: [4, 2, 3, 1]

Explanation:

The nodes with odd indices are 4, 2 and the ones with even indices are 3, 1.
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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }
    void segregateOddEven(){
        if (!head || !head->next)
            return;

        Node* odd = head;
        Node* even = head->next;
        Node* evenStart = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenStart;
    }

    void display(){
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    int arr[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        list.insert(arr[i]);

    cout << "Original List:\n";
    list.display();

    list.segregateOddEven();

    cout << "After Rearranging:\n";
    list.display();

    return 0;
}
