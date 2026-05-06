/*
XOR of numbers in a given range

Given two integers L and R. Find the XOR of the elements in the range [L , R].


Example 1

Input : L = 3 , R = 5

Output : 2

Explanation : answer = (3 ^ 4 ^ 5) = 2.

Example 2

Input : L = 1, R = 3

Output : 0

Explanation : answer = (1 ^ 2 ^ 3) = 0.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int xorTillN(int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        return 0;
    }
    int findXOR(int L, int R) {
        return xorTillN(R) ^ xorTillN(L - 1);
    }
};

int main() {

    int L, R;
    cin >> L >> R;
    Solution obj;
    cout << obj.findXOR(L, R);

    return 0;
}