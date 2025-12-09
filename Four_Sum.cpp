/*
4 Sum
Easy

Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:



a, b, c, d are all distinct valid indices of nums.


nums[a] + nums[b] + nums[c] + nums[d] == target.


Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.


Examples:
Input: nums = [1, -2, 3, 5, 7, 9], target = 7

Output: [[-2, 1, 3, 5]]

Explanation:

nums[1] + nums[0] + nums[2] + nums[3] = 7

Input: nums = [7, -7, 1, 2, 14, 3], target = 9

Output: []

Explanation:

No quadruplets are present which add upto 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int st = j + 1, end = nums.size() - 1;

                while (st < end) {
                    long long sum = (long long)nums[i] + nums[j] + nums[st] + nums[end];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[st], nums[end]});

                        while (st < end && nums[st] == nums[st + 1]) st++;
                        while (st < end && nums[end] == nums[end - 1]) end--;

                        st++;
                        end--;
                    }
                    else if (sum < target) st++;
                    else end--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, -2, 3, 5, 7, 9};
    int target = 7;

    vector<vector<int>> result = sol.fourSum(nums, target);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j + 1 < result[i].size()) cout << ", ";
        }
        cout << "]";
        if (i + 1 < result.size()) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
