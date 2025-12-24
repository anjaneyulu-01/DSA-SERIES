/*
Search in rotated sorted array-I

Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.


Example 1

Input : nums = [4, 5, 6, 7, 0, 1, 2], k = 0

Output: 4

Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Example 2

Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3

Output: -1

Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int Serach(vector<int>&nums ,int target){
    int low=0, high=nums.size()-1;
    while(low<=high){
     int mid=low+(high-low)/2;
     if(nums[mid]==target)return mid;
     if(nums[low]<=nums[mid]){
      if(nums[low]<=target && nums[mid]>target){
        high=mid-1;
      }
      else{
        low=mid+1;
      }
     }else{
        if(nums[mid]<target && nums[high]>=target){
          high=mid+1;
        }
        else{
          low=mid-1;
        }
     }
    }
    return -1;
  }
};

int main(){
  vector<int>nums={4, 5, 6, 7, 0, 1, 2};
  int target=0;
  Solution obj;
  cout<<obj.Serach(nums,target);
  return 0;
}