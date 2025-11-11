/*
Largest Element


0

100
Easy

Given an array of integers nums, return the value of the largest element in the array


Examples:
Input: nums = [3, 3, 6, 1]

Output: 6

Explanation: The largest element in array is 6

Input: nums = [3, 3, 0, 99, -40]

Output: 99

Explanation: The largest element in array is 99
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int largestNumber(vector<int>&nums){
    int largest=INT_MIN;
    for(int i=0; i<nums.size(); i++){
      if(nums[i]>largest){
        largest=nums[i];
      }
    }
    return largest;
  }
};

int main(){
  vector<int>nums={1,2,3,4,5,6};
  Solution obj;
  cout<<obj.largestNumber(nums);
  return 0;
}