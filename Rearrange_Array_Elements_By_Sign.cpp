/*
Rearrange array elements by sign

Medium

Given an integer array nums of even length consisting of an equal number of positive and negative integers.Return the answer array in such a way that the given conditions are met:



Every consecutive pair of integers have opposite signs.


For all integers with the same sign, the order in which they were present in nums is preserved.


The rearranged array begins with a positive integer.

Examples:
Input : nums = [2, 4, 5, -1, -3, -4]

Output : [2, -1, 4, -3, 5, -4]

Explanation:

The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4 maintain their relative positions

Input : nums = [1, -1, -3, -4, 2, 3]

Output : [1, -1, 2, -3, 3, -4]

Explanation:

The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4 maintain their relative positions
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     vector<int>pos,neg;
     for(int i=0; i<nums.size(); i++){
        if(nums[i]>0)pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
     }
     int p=0,n=0;
     for(int i=0; i<nums.size(); i++){
      if(i%2==0){
        nums[i]=pos[p];
        p++;
      }
      else{
        nums[i]=neg[n];
        n++;
      }
     }
     return nums;
    }
};


int main(){
  vector<int>nums={2, 4, 5, -1, -3, -4};
 Solution obj;
 vector<int>ans=obj.rearrangeArray(nums);
 for(int i=0; i<ans.size(); i++){
  cout<<ans[i]<<" ";
 }
 return 0;
}