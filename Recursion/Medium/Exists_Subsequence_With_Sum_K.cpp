/*
Check if there exists a subsequence with sum K
Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.


Example 1

Input : nums = [1, 2, 3, 4, 5] , k = 8

Output : Yes

Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

Example 2

Input : nums = [4, 3, 9, 2] , k = 10

Output : No

Explanation : No subsequence can sum up to 10.
*/

#include <iostream>
#include <vector>
using namespace std;

class SubsequenceSum {
public:
    
    bool checkSum(int index, vector<int>& nums, int k) {
        
        // If sum becomes 0, we found a subsequence
        if (k == 0) return true;

        // If we reached end or k becomes negative
        if (index == nums.size() || k < 0) return false;

        // Pick the element
        if (checkSum(index + 1, nums, k - nums[index]))
            return true;

        // Do not pick the element
        if (checkSum(index + 1, nums, k))
            return true;

        return false;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 8;

    SubsequenceSum obj;

    if (obj.checkSum(0, nums, k))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}