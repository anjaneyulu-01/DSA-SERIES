/*
Check if the Array is Sorted

Easy

Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.


Examples:
Input : nums = [1, 2, 3, 4, 5]

Output : true

Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.

Input : nums = [1, 2, 1, 4, 5]

Output : false

Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  bool check(vector<int>&nums){
    for(int i=0; i<nums.size()-1; i++){
      if(nums[i]>nums[i+1])return false;
    }
    return true;
  }
};

int main(){
  vector<int>nums={1,2,4,1,4,5,6};
  Solution obj;
  cout<<obj.check(nums);
  return 0;
}