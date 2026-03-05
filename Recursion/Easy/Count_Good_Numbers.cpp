/*
Count Good Numbers
A digit string is considered good if the digits at even indices (0-based) are even digits (0, 2, 4, 6, 8) and the digits at odd indices are prime digits (2, 3, 5, 7).



Given an integer n, return the total number of good digit strings of length n. As the result may be large, return it modulo 109 + 7.



A digit string is a string consisting only of the digits '0' through '9'. It may contain leading zeros.


Example 1

Input: n = 1

Output: 5

Explanation:

Only one index (0) → must be even.

Valid strings: "0", "2", "4", "6", "8"

Example 2

Input: n = 2

Output: 20

Explanation:

Index 0: 5 options (even digits)

Index 1: 4 options (prime digits)

Total: 5 * 4 = 20

*/

#include <iostream>
using namespace std;

class Solution {
public:
    long long mod = 1000000007;
    long long power(long long base, long long exp){
        long long result = 1;

        while(exp > 0){
            if(exp % 2 == 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n){
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenPart = power(5, even);
        long long oddPart = power(4, odd);

        return (evenPart * oddPart) % mod;
    }
};

int main() {
    Solution obj;

    long long n = 1; 
    cout << obj.countGoodNumbers(n);

    return 0;
}