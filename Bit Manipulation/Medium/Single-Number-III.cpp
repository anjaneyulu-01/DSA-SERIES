/*
Single Number - III
Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.
For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].
Example 1

Input : nums = [1, 2, 1, 3, 5, 2]

Output : [3, 5]

Explanation : The integers 3 and 5 have appeared only once.

Example 2

Input : nums = [-1, 0]

Output : [-1, 0]

Explanation : The integers -1 and 0 have appeared only once.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> singleNumber(vector<int>& nums) {

        int xr = 0;

        for(int num : nums) {
            xr ^= num;
        }
        int rightmost = xr & (-xr);

        int num1 = 0;
        int num2 = 0;
        for(int num : nums) {

            if(num & rightmost) {
                num1 ^= num;
            }
            else {
                num2 ^= num;
            }
        }
        if(num1 > num2) {
            swap(num1, num2);
        }

        return {num1, num2};
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    Solution obj;
    vector<int> ans = obj.singleNumber(nums);
    cout << "Unique numbers are: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}