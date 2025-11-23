/*
Longest subarray with sum K


0

100
Medium

Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.


Examples:
Input: nums = [10, 5, 2, 7, 1, 9],  k=15

Output: 4

Explanation:

The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Input: nums = [-3, 2, 1], k=6

Output: 0

Explanation:

There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  int longestSubarray(vector<int> &nums, int k){
      int left=0,right=0;
      long long sum=0;
      long long maxlen=0;
      int n=nums.size();
      while(right<n){
      sum+=nums[right];
        while(left<=right && sum>k){
          sum-=nums[left];
          left++;
        }
        if(sum==k){
          maxlen=max(maxlen,(long long)(right-left+1));

        }
        right++;
        
      
      }
      return maxlen;
  }
};

int main(){
  vector<int>nums={10, 5, 2, 7, 1, 9};
  int k=15;
  Solution obj;
  cout<<obj.longestSubarray(nums,k);
  return 0;
}