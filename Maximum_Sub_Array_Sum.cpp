/*
Kadane's Algorithm

Medium

Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.



A subarray is a contiguous non-empty sequence of elements within an array.


Examples:
Input: nums = [2, 3, 5, -2, 7, -4]

Output: 15

Explanation:

The subarray from index 0 to index 4 has the largest sum = 15

Input: nums = [-2, -3, -7, -2, -10, -4]

Output: -2

Explanation:

The element on index 0 or index 3 make up the largest sum when taken as a subarray
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int MaximumSubArraySum(vector<int>&nums){
    int maxsum=INT_MIN;
    int sum=0;
    for(int i=0; i<nums.size(); i++){
      sum+=nums[i];
      maxsum=max(maxsum,sum);
      if(sum<0){
        sum=0;
      }
    }
   return maxsum;
  }
};

int main(){
  vector<int>nums={2, 3, 5, -2, 7, -4};
  Solution obj;
  cout<<obj.MaximumSubArraySum(nums);
  return 0;
}