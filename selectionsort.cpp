/*
Selection Sort
Easy

Given an array of integers nums, sort the array in non-decreasing order using the selection sort algorithm and return the sorted array.



A sorted array in non-decreasing order is an array where each element is greater than or equal to all previous elements in the array.


Examples:
Input: nums = [7, 4, 1, 5, 3]

Output: [1, 3, 4, 5, 7]

Explanation: 1 <= 3 <= 4 <= 5 <= 7.

Thus the array is sorted in non-decreasing order.

Input: nums = [5, 4, 4, 1, 1]

Output: [1, 1, 4, 4, 5]

Explanation: 1 <= 1 <= 4 <= 4 <= 5.

Thus the array is sorted in non-decreasing order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:

  void selectionsort(vector<int>&nums){
    for(int i=0; i<nums.size(); i++){
      int smallest=i;
      for(int j=i; j<nums.size(); j++){
        if(nums[j]<nums[smallest]){
          smallest=j;
        }
      }
      swap(nums[i],nums[smallest]);
    }
    }
};

int main(){
  vector<int>nums={6,4,3,5,2,6,1,7};
  Solution obj;
  obj.selectionsort(nums);
  for(int i=0; i<nums.size(); i++){
    cout<<nums[i]<<" ";
  }
  return 0;
}