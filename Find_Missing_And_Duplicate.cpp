/*
Find the repeating and missing number

Company
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.



Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.



Note: You are not allowed to modify the original array.


Example 1

Input: nums = [3, 5, 4, 1, 1]

Output: [1, 2]

Explanation:

1 appears two times in the array and 2 is missing from nums

Example 2

Input: nums = [1, 2, 3, 6, 7, 5, 7]

Output: [7, 4]

Explanation:

7 appears two times in the array and 4 is missing from nums.


*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findRepeatingAndMissing(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int num : nums) {
        mp[num]++;
    }

    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (mp[i] == 2)
            repeating = i;
        else if (mp[i] == 0)
            missing = i;
    }

    return {repeating, missing};
}

int main() {
    vector<int> nums1 = {3, 5, 4, 1, 1};
    vector<int> ans1 = findRepeatingAndMissing(nums1);
    vector<int> nums2 = {1, 2, 3, 6, 7, 5, 7};
    vector<int> ans2 = findRepeatingAndMissing(nums2);
    cout << "Repeating: " << ans2[0] << ", Missing: " << ans2[1] << endl;

    return 0;
}
