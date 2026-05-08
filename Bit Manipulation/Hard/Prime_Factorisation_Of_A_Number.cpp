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
        vector<int> factors;
        while(n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }
        for(int i = 3; i * i <= n; i += 2) {
            while(n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }
        if(n > 1) {
            factors.push_back(n);
        }

        return factors;
    }
    vector<vector<int>> primeFactors(vector<int>& queries) {
        vector<vector<int>> result;

        for(int num : queries) {
            result.push_back(primeFactorisation(num));
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of queries: ";
    cin >> n;

    vector<int> queries(n);
    cout << "Enter numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> queries[i];
    }
    Solution obj;
    vector<vector<int>> ans = obj.primeFactors(queries);
    cout << "\nPrime Factorisation:\n";

    for(int i = 0; i < ans.size(); i++) {

        cout << queries[i] << " -> ";

        cout << "[ ";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }

    return 0;
}