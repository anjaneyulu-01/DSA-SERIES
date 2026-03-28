/*
Subsets I
Given an array nums of n integers. Return array of sum of all subsets of the array nums.



Output can be returned in any order.


Example 1

Input : nums = [2, 3]

Output : [0, 2, 3, 5]

Explanation :

When no elements is taken then Sum = 0.

When only 2 is taken then Sum = 2.

When only 3 is taken then Sum = 3.

When element 2 and 3 are taken then sum = 2+3 = 5.

Example 2

Input : nums = [5, 2, 1]

Output : [0, 1, 2, 3, 5, 6, 7, 8]

Explanation :

When no elements is taken then Sum = 0.

When only 5 is taken then Sum = 5.

When only 2 is taken then Sum = 2.

When only 1 is taken then Sum = 1.

When element 2 and 1 are taken then sum = 2+1 = 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int index, int sum, vector<int>& nums, vector<int>& result) {
        if (index == nums.size()) {
            result.push_back(sum);
            return;
        }
        solve(index + 1, sum + nums[index], nums, result);
        solve(index + 1, sum, nums, result);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> result;
        solve(0, 0, nums, result);
        return result;
    }
};

int main() {
    vector<int> nums = {2, 3};

    Solution obj; 
    vector<int> ans = obj.subsetSums(nums);
    cout << "Subset sums are: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}