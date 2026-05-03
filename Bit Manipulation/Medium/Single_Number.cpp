/*
Single Number - I

Given an array of nums of n integers. Every integer in the array appears twice except one integer. Find the number that appeared once in the array.
Example 1

Input : nums = [1, 2, 2, 4, 3, 1, 4]

Output : 3

Explanation : The integer 3 has appeared only once.

Example 2

Input : nums = [5]

Output : 5

Explanation : The integer 5 has appeared only once.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            result ^= num; 
        }

        return result;
    }
};

int main() {
    Solution obj; 

    vector<int> nums = {1, 2, 2, 4, 3, 1, 4};

    int result = obj.singleNumber(nums);

    cout << "Single number is: " << result << endl;

    return 0;
}