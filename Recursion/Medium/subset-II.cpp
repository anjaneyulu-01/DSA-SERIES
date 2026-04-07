/*
Subsets II
Given an integer array nums, which can have duplicate entries, provide the power set.



Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.


Example 1

Input : nums = [1, 2, 2]

Output : [ [ ] , [1] , [1, 2] , [1, 2, 2] , [2] , [2, 2] ]

Example 2

Input : nums = [1, 2]

Output : [ [ ], [1] , [2] , [1, 2] ]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            backtrack(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());
        backtrack(0, nums, temp, ans);

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = obj.subsetsWithDup(nums);
    cout << "Subsets are:\n";
    for (auto subset : result) {
        cout << "[ ";
        for (auto val : subset) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}