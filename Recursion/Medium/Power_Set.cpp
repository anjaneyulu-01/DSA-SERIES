/*
Power Set
Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.



Do not include the duplicates in the answer.


Example 1

Input : nums = [1, 2, 3]

Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]

Example 2

Input : nums = [1, 2]

Output : [ [ ] , [1] , [2] , [1,2] ]
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        
        // store current subset
        result.push_back(current);

        for(int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);                // include element
            generateSubsets(i + 1, nums, current, result);
            current.pop_back();                        // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        generateSubsets(0, nums, current, result);
        return result;
    }
};

int main() {

    vector<int> nums = {1,2,3};   // given input

    Solution obj;                 // object creation

    vector<vector<int>> ans = obj.subsets(nums);

    cout<<"Power Set:"<<endl;

    for(auto subset : ans){
        cout<<"[ ";
        for(auto x : subset){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}