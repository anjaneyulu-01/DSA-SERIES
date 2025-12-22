/*
First and last occurrence

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1].


Example 1

Input: nums = [5, 7, 7, 8, 8, 10], target = 8

Output: [3, 4]

Explanation:The target is 8, and it appears in the array at indices 3 and 4, so the output is [3,4]

Example 2

Input: nums = [5, 7, 7, 8, 8, 10], target = 6

Output: [-1, -1]

Expalantion: The target is 6, which is not present in the array. Therefore, the output is [-1, -1].
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();

    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int last  = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    if (first == n || nums[first] != target)
        return {-1, -1};

    return {first, last};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
