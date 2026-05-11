/*
Prime factorisation of a Number

You are given an integer array queries of length n.

Return the prime factorization of each number in array queries in sorted order.


Example 1

Input : queries = [2, 3, 4, 5, 6]

Output : [ [2], [3], [2, 2], [5], [2, 3] ]

Explanation : The values 2, 3, 5 are itself prime numbers.

The prime factorization of 4 will be --> 2 * 2.

The prime factorization of 6 will be --> 2 * 3.

Example 2

Input : queries = [7, 12, 18]

Output : [ [7], [2, 2, 3], [2, 3, 3] ]

Explanation : The value 7 itself is a prime number.

The prime factorization of 12 will be --> 2 * 2 * 3.

The prime factorization of 18 will be --> 2 * 3 * 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> primeFactorisation(int n) {

        vector<int> ans;

        for(int i = 2; i * i <= n; i++) {

            while(n % i == 0) {
                ans.push_back(i);
                n /= i;
            }
        }

        if(n > 1) {
            ans.push_back(n);
        }

        return ans;
    }
};

int main() {

    int n;
    cin >> n;

    Solution obj;

    vector<int> result = obj.primeFactorisation(n);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}