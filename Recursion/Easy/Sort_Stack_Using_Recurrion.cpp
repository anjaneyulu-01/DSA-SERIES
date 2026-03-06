/*
Sort a Stack
You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).


Example 1

Input: stack = [4, 1, 3, 2]

Output: [4, 3, 2, 1]

Explanation:

After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.



Example 2

Input: stack = [1]

Output: [1]

Explanation:

A single-element stack is already sorted.


*/

#include <iostream>
#include <stack>
using namespace std;

class StackSorter{
public:
    void insertSorted(stack<int> &st, int x){
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertSorted(st, x);

        st.push(temp);
    }
    void sortStack(stack<int> &st){
        if(st.empty()){
            return;
        }

        int x = st.top();
        st.pop();

        sortStack(st);

        insertSorted(st, x);
    }

    void printStack(stack<int> st){
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main(){

    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    StackSorter obj;   

    obj.sortStack(st);

    cout << "Sorted Stack (Top to Bottom): ";
    obj.printStack(st);

    return 0;
}