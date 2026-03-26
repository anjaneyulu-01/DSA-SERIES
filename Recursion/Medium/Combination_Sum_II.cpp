/*
Combination Sum II
Given collection of candidate numbers (candidates) and a integer target.Find all unique combinations in candidates where the sum is equal to the target.There can only be one usage of each number in the candidates combination and return the answer in sorted order.



e.g : The combination [1, 1, 2] and [1, 2, 1] are not unique.


Example 1

Input : candidates = [2, 1, 2, 7, 6, 1, 5] , target = 8

Output : [ [1, 1, 6] , [1, 2, 5] , [1, 7] , [2, 6] ]

Explanation : The combinations sum up to target are

1 + 1 + 6 => 8.

1 + 2 + 5 => 8.

1 + 7 => 8.

2 + 6 => 8.

Example 2

Input : candidates = [2, 5, 2, 1, 2] , target = 5

Output : [ [1, 2, 2] , [5] ]

Explanation : The combinations sum up to target are

1 + 2 + 2 => 5.

5 => 5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& candidates, int target,
                   vector<int>& current, vector<vector<int>>& result) {
        
        // Base case
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            current.push_back(candidates[i]);

            backtrack(i + 1, candidates, target - candidates[i], current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Step 1: Sort
        sort(candidates.begin(), candidates.end());

        backtrack(0, candidates, target, current, result);

        return result;
    }
};

int main() {

    vector<int> candidates = {2, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution obj;

    vector<vector<int>> result = obj.combinationSum2(candidates, target);
    cout << "Output:\n";
    for (auto &comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}