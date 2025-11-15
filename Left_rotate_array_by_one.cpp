/*
Left Rotate Array by One

Easy

Given an integer array nums, rotate the array to the left by one.



Note: There is no need to return anything, just modify the given array.


Examples:
Input: nums = [1, 2, 3, 4, 5]

Output: [2, 3, 4, 5, 1]

Explanation:

Initially, nums = [1, 2, 3, 4, 5]

Rotating once to left -> nums = [2, 3, 4, 5, 1]

Input: nums = [-1, 0, 3, 6]

Output: [0, 3, 6, -1]

Explanation:

Initially, nums = [-1, 0, 3, 6]

Rotating once to left -> nums = [0, 3, 6, -1]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
void RotateArr(vector<int>&nums){
  int num=nums[0];
  for(int i=0; i<nums.size()-1; i++){
    nums[i]=nums[i+1];
  }
  nums[nums.size()-1]=num;
}
};

int main(){
  vector<int>nums={1,2,3,4,5,6};
  Solution obj;
  obj.RotateArr(nums);
  for(int i=0; i<nums.size(); i++){
    cout<<nums[i]<<" ";
  }
  return 0;
}