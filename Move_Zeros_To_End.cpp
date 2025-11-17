/*
Move Zeros to End


0

100
Easy

Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.



This must be done in place, without making a copy of the array.


Examples:
Input: nums = [0, 1, 4, 0, 5, 2]

Output: [1, 4, 5, 2, 0, 0]

Explanation:

Both the zeroes are moved to the end and the order of the other elements stay the same

Input: nums = [0, 0, 0, 1, 3, -2]

Output: [1, 3, -2, 0, 0, 0]

Explanation:

All 3 zeroes are moved to the end and the order of the other elements stay the same
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  void MoveZeros(vector<int>&nums){
    int i=0;
    for(int j=0; j<nums.size(); j++){
      if(nums[j]!=0){
        nums[i]=nums[j];
        i++;
      }
    }
    for(int j=i; j<nums.size(); j++){
      nums[j]=0;
    }
  }
};

int main(){
  vector<int>nums={0, 0, 0, 1, 3, -2};
  Solution obj;
  obj.MoveZeros(nums);
  for(int val:nums){
    cout<<val<<" ";
  }
  return 0;
}