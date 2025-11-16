/*
Left Rotate Array by K Places

Easy

Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.


Examples:
Input: nums = [1, 2, 3, 4, 5, 6], k = 2

Output: nums = [3, 4, 5, 6, 1, 2]

Explanation:

rotate 1 step to the left: [2, 3, 4, 5, 6, 1]

rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]

Input: nums = [3, 4, 1, 5, 3, -5], k = 8

Output: nums = [1, 5, 3, -5, 3, 4]

Explanation:

rotate 1 step to the left: [4, 1, 5, 3, -5, 3]

rotate 2 steps to the left: [1, 5, 3, -5, 3, 4]

rotate 3 steps to the left: [5, 3, -5, 3, 4, 1]

rotate 4 steps to the left: [3, -5, 3, 4, 1, 5]

rotate 5 steps to the left: [-5, 3, 4, 1, 5, 3]

rotate 6 steps to the left: [3, 4, 1, 5, 3, -5]

rotate 7 steps to the left: [4, 1, 5, 3, -5, 3]

rotate 8 steps to the left: [1, 5, 3, -5, 3, 4]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  void Rotate(vector<int>&nums,int d){
    int n=nums.size();
    d=d%n;
    for(int i=0; i<d; i++){
      int temp=nums[0];
      for(int i=0; i<nums.size()-1; i++){
        nums[i]=nums[i+1];
      }
      nums[n-1]=temp;
    }
  }
};

int main(){
  vector<int>nums={3, 4, 1, 5, 3, -5};
  int d=8;
  Solution obj;
  obj.Rotate(nums,d);
  for(int i=0; i<nums.size(); i++){
    cout<<nums[i]<<" ";
  }
  return 0;
}