/*
Combination Sum

Provided with a goal integer target and an array of unique integer candidates, provide a list of all possible combinations of candidates in which the selected numbers add up to the target. The combinations can be returned in any order.



A candidate may be selected from the pool an infinite number of times. There are two distinct combinations if the frequency of at least one of the selected figures differs.



The test cases are created so that, for the given input, there are fewer than 150 possible combinations that add up to the target.

If there is no possible subsequences then return empty vector.


Example 1

Input : candidates = [2, 3, 5, 4] , target = 7

Output : [ [2, 2, 3] , [3, 4] , [5, 2] ]

Explanation :

2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.

5 and 2 are candidates, and 5 + 2 = 7.

3 and 4 are candidates, and 3 + 4 = 7.

There are total three combinations.

Example 2

Input : candidates = [2], target = 1

Output : []

Explanation : There is no way we can choose the candidates to sum up to target.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, 
               vector<int>& temp, vector<vector<int>>& ans) {
        
        // Base case
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Traverse candidates
        for (int i = index; i < candidates.size(); i++) {
            // If current element is greater than target, skip
            if (candidates[i] > target) continue;

            // Pick the element
            temp.push_back(candidates[i]);

            // Stay at same index (can reuse same element)
            solve(i, candidates, target - candidates[i], temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        // Optional: sort for optimization
        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, temp, ans);
        return ans;
    }
};

int main() {
    // Input
    vector<int> candidates = {3, 4, 5, 6};
    int target = 10;

    // Object creation
    Solution obj;

    // Function call
    vector<vector<int>> result = obj.combinationSum(candidates, target);

    // Output
    cout << "Combinations are:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}