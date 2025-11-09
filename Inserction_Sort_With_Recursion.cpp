/*
Recursive Insertion Sort


0

100
Easy

Given an array of integers nums, sort the array in non-decreasing order using the recursive Insertion Sort algorithm, and return the sorted array.

You must implement Insertion Sort using recursion only.
Do not use loops (like for or while) or built-in sorting functions (sort, Arrays.sort, etc.).
A sorted array in non-decreasing order is an array where each element is greater than or equal to all elements that come before it.

Examples:
Input: nums = [7, 4, 1, 5, 3]

Output: [1, 3, 4, 5, 7]

Explanation: 1 <= 3 <= 4 <= 5 <= 7.

Thus the array is sorted in non-decreasing order.

Input: nums = [5, 4, 4, 1, 1]

Output: [1, 1, 4, 4, 5]

Explanation: 1 <= 1 <= 4 <= 4 <= 5.

Thus the array is sorted in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void insert(vector<int>& nums, int temp) {

        if (nums.size() == 0 || nums.back() <= temp) {
            nums.push_back(temp);
            return;
        }

        int val = nums.back();
        nums.pop_back();
        insert(nums, temp);
        nums.push_back(val);
    }

    void recursiveInsertionSort(vector<int>& nums) {

        if (nums.size() <= 1)
            return;
        int temp = nums.back();
        nums.pop_back();
        recursiveInsertionSort(nums);
        insert(nums, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        recursiveInsertionSort(nums);
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7, 4, 1, 5, 3};
    vector<int> ans = s.sortArray(nums);
    for (int n : ans) cout << n << " ";
    return 0;
}
