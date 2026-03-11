
/*
Count all subsequences with sum K
Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.


Example 1

Input : nums = [4, 9, 2, 5, 1] , k = 10

Output : 2

Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

Example 2

Input : nums = [4, 2, 10, 5, 1, 3] , k = 5

Output : 3

Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int countSubseq(int index, int sum, vector<int>& nums, int k) {

        if(index == nums.size()) {
            if(sum == k)
                return 1;
            return 0;
        }

        // Take the element
        int take = countSubseq(index + 1, sum + nums[index], nums, k);

        // Do not take the element
        int notTake = countSubseq(index + 1, sum, nums, k);

        return take + notTake;
    }

    int countSubsequences(vector<int>& nums, int k) {
        return countSubseq(0, 0, nums, k);
    }
};

int main() {

    vector<int> nums = {4, 9, 2, 5, 1};
    int k = 10;

    Solution obj;

    int result = obj.countSubsequences(nums, k);

    cout << "Number of subsequences with sum " << k << " = " << result;

    return 0;
}