/*
Check if a Number is Power of 2 or Not
Given an integer n, return true if it is a power of two. Otherwise, return false.



An integer n is a power of two if there exists an integer x such that n == 2x.



You must solve it without using loops or recursion.


Example 1

Input: n = 1

Output: true

Explanation: 20 = 1

Example 2

Input: n = 16

Output: true

Explanation: 24 = 16
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution obj;
    if (obj.isPowerOfTwo(n)) {
        cout << "True - It is a Power of 2" << endl;
    } else {
        cout << "False - It is NOT a Power of 2" << endl;
    }

    return 0;
}