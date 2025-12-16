/*
Maximum Product Subarray in an Array

Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray.



A subarray is a contiguous non-empty sequence of elements within an array.


Example 1

Input: nums = [4, 5, 3, 7, 1, 2]

Output: 840

Explanation:

The largest product is given by the whole array itself

Example 2

Input: nums = [-5, 0, -2]

Output: 0

Explanation:

The largest product is achieved with the following subarrays [0], [-5, 0], [0, -2], [-5, 0, -2].
*/

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(maxProd, minProd);

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        ans = max(ans, maxProd);
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 5, 3, 7, 1, 2};
    cout << maxProduct(nums);
    return 0;
}


