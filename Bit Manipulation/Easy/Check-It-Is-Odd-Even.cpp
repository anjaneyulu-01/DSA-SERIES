/*
Check if a Number is Odd or Not
Given a non-negative integer n, determine whether it is odd.

Return true if the number is odd, otherwise return false.



A number is odd if it is not divisible by 2 (i.e., n % 2 != 0).


Example 1

Input: n = 7

Output: true

Explanation: 7 is not divisible by 2. Hence, it is odd.

Example 2

Input: n = 0

Output: false

Explanation: 0 is divisible by 2. Hence, it is not odd.

*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isOdd(int n) {

        return (n % 2 != 0);
    }
};

int main() {
    int n;
    
    cout << "Enter a number: ";
    cin >> n;

    Solution obj;
    bool result = obj.isOdd(n);
    if(result)
        cout << "true (Number is Odd)" << endl;
    else
        cout << "false (Number is Even)" << endl;

    return 0;
}