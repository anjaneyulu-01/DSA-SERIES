/*
Merge Overlapping Subintervals

Medium

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.



You can return the intervals in any order.


Examples:
Input: intervals = [[1,5],[3,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Intervals [1,5] and [3,6] overlap, so they are merged into [1,6].

Input: intervals = [[5,7],[1,3],[4,6],[8,10]]

Output: [[1,3],[4,7],[8,10]]

Explanation: Intervals [4,6] and [5,7] overlap and are merged into [4,7].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (ans.empty() || nums[i][0] > ans.back()[1]) {
                ans.push_back(nums[i]); 
            } else {
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
        }
        return ans;
    }
};

int main() {
 
    vector<vector<int>> intervals = {{1,5}, {3,6}, {8,10}, {15,18}};

    Solution obj;
    vector<vector<int>> result = obj.mergeOverlap(intervals);

   
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]";

    return 0;
}
