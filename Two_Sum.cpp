/*
Two Sum

Easy

Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.



Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in increasing order.


Examples:
Input: nums = [1, 6, 2, 10, 3], target = 7

Output: [0, 1]

Explanation:

nums[0] + nums[1] = 1 + 6 = 7

Input: nums = [1, 3, 5, -7, 6, -3], target = 0

Output: [1, 5]

Explanation:

nums[1] + nums[5] = 3 + (-3) = 0
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
        
            if (mp.find(complement) != mp.end()) {
                int a = mp[complement];
                int b = i;
                if (a < b) return {a, b};
                else return {b, a};
            }
            
         
            mp[nums[i]] = i;
        }
        
        return {}; 
    }
};

int main(){
  vector<int>nums={1, 3, 5, -7, 6, -3};
  int target=0;
  Solution obj;
  vector<int>ans=obj.twoSum(nums,target);
  for(int val:ans){
    cout<<val<<" ";
  }
  return 0;
}