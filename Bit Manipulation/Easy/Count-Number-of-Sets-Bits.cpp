/*
Count the Number of Set Bits
Given an integer n, return the number of set bits (1s) in its binary representation.



Can you solve it in O(log n) time complexity?


Example 1

Input: n = 5

Output: 2

Explanation: The binary representation of 5 is 101, which has 2 set bits.

Example 2

Input: n = 15

Output: 4

Explanation: The binary representation of 15 is 1111, which has 4 set bits.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;

        while (n > 0) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution obj;
    int result = obj.countSetBits(n);

    cout << "Number of set bits: " << result << endl;

    return 0;
}