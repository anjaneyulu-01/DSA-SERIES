/*
Search insert position
Given a sorted array of nums consisting of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.


Example 1

Input: nums = [1, 3, 5, 6], target = 5

Output: 2

Explanation: The target value 5 is found at index 2 in the sorted array. Hence, the function returns 2.

Example 2

Input: nums = [1, 3, 5, 6], target = 2

Output: 1

Explanation: The target value 2 is not found in the array. However, it should be inserted at index 1 to maintain the sorted order of the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int InsertPosition(vector<int>&nums,int x){
    int low=0,high=nums.size()-1;
    while(low<=high){
      int mid=low+(high-low)/2;
      if(nums[mid]>=x){
        high=mid-1;
      }
      else{
        low=mid+1;
      }
    }
    return low;
  }
};

int main(){
  vector<int>nums={1, 3, 5, 6};
  int x=5;
  Solution obj;
  cout<<obj.InsertPosition(nums,x);
  return 0;
}