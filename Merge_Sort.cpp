/*
Merge Sorting


0

100
Medium

Given an array of integers, nums,sort the array in non-decreasing order using the merge sort algorithm. Return the sorted array.



A sorted array in non-decreasing order is one in which each element is either greater than or equal to all the elements to its left in the array.


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
void merge(vector<int>&nums,int low,int mid, int high){
  vector<int>ans;
  ans.reserve(high - low + 1);
  int left=low;
  int right=mid+1;
  while(left<=mid && right<=high){
    if(nums[left]<=nums[right]){
      ans.push_back(nums[left]);
      left++;
    }
    else{
      ans.push_back(nums[right]);
      right++;
    }
  }
  while(left<=mid){
    ans.push_back(nums[left]);
    left++;
  }
  while(right<=high){
    ans.push_back(nums[right]);
    right++;
  }
  for(int i=low; i<=high; i++){
    nums[i]=ans[i-low];
  }
}
void mergesort(vector<int>&nums,int low,int high){
  if(low>=high)return;
  int mid=low+(high-low)/2;
  mergesort(nums,low,mid);
  mergesort(nums,mid+1,high);
  merge(nums,low,mid,high);
}
void merge_sort(vector<int>&nums){
  int n=nums.size();
  mergesort(nums,0,n-1);
}
};

int main(){
  vector<int>nums={1,7,4,8,3,2,5,1,9};
  Solution obj;
  obj.merge_sort(nums);
  for(auto x:nums){
    cout<<x<<" ";
  }
  return 0;
}