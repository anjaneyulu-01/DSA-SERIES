/*
Reverse a Stack
You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.



Your solution must modify the input stack in-place to reverse the order of its elements.


Example 1

Input: stack = [4, 1, 3, 2]

Output: [2, 3, 1, 4]

Example 2

Input: stack = [10, 20, -5, 7, 15]

Output: [15, 7, -5, 20, 10]


*/

#include <iostream>
#include <stack>
using namespace std;

class StackReverse {
public:
    void insertAtBottom(stack<int> &st, int x) {
        if(st.empty()) {
            st.push(x);
            return;
        }

        int top = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(top);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty())
            return;

        int top = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, top);
    }
    void printStack(stack<int> st) {
        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main(){

    stack<int> st;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter stack elements:\n";

    for(int i = 0; i < n; i++){
        cin >> x;
        st.push(x);
    }

    StackReverse obj;

    cout << "Original Stack (Top to Bottom): ";
    obj.printStack(st);

    obj.reverseStack(st);

    cout << "Reversed Stack (Top to Bottom): ";
    obj.printStack(st);

    return 0;
}