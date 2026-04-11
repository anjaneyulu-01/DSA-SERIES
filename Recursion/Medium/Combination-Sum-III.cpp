/*
Combination Sum III
Determine all possible set of k numbers that can be added together to equal n while meeting the following requirements:



There is only use of numerals 1 through 9.
A single use is made of each number.


Return list of every feasible combination that is allowed. The combinations can be returned in any order, but the list cannot have the same combination twice.


Example 1

Input : k = 3 , n = 7

Output : [ [1, 2, 4] ]

Explanation :

1 + 2 + 4 = 7

There are no other valid combinations.

Example 2

Input : k = 3, n = 9

Output : [[1, 2, 6],[1, 3, 5],[2, 3, 4]]

Explanation :

1 + 2 + 6 = 9

1 + 3 + 5 = 9

2 + 3 + 4 = 9

There are no other valid combinations.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int start, int k, int n, vector<int>& temp, vector<vector<int>>& ans) {
        // Base case
        if (k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }

        // Invalid case
        if (k == 0 || n < 0) return;

        // Try numbers from start to 9
        for (int i = start; i <= 9; i++) {
            temp.push_back(i);                 // choose
            solve(i + 1, k - 1, n - i, temp, ans); // explore
            temp.pop_back();                  // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(1, k, n, temp, ans);
        return ans;
    }
};

int main() {
    Solution obj;   // object creation

    int k = 3, n = 9;

    vector<vector<int>> result = obj.combinationSum3(k, n);

    cout << "Output:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}