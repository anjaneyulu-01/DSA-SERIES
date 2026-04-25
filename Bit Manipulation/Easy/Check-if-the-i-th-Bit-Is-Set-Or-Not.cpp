/*
Check if the i-th bit is Set or Not
Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.


Example 1

Input: n = 5, i = 0

Output: true

Explanation: Binary representation of 5 is 101. The 0-th bit from LSB is set (1).



Example 2

Input: n = 10, i = 1

Output: true

Explanation: Binary representation of 10 is 1010. The 1-st bit from LSB is set (1).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isKthBitSet(int n, int i) {
        if (n & (1 << i)) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution obj;

    int n = 5;
    int i = 0;

    bool result = obj.isKthBitSet(n, i);

    if (result) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}