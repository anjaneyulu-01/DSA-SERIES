/*
Split array - largest sum

Given an integer array a of size n and an integer k. Split the array a into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.


Example 1

Input: a = [1, 2, 3, 4, 5], k = 3

Output:6

Explanation: There are many ways to split the array a[] into k consecutive subarrays. The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.

Example 2

Input: a = [3,5,1], k = 3

Output: 5

Explanation: There is only one way to split the array a[] into 3 subarrays, i.e., [3], [5], and [1]. The largest sum among these subarrays is 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvalid(const vector<int>&nums,long long mid,int k){
        long long sum=0;
        int p=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>mid)return false;
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                p++;
                sum=nums[i];
                if(p>k)return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
      long long largest=INT_MIN;
      long long sum=0;
      int ans=-1;
      for(auto val:nums){
        if(val>largest){
            largest=val;
        }
        sum+=val;
      }  
      long long low=largest,high=sum;
      while(low<=high){
        long long mid=low+(high-low)/2;
        if(isvalid(nums,mid,k)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
      }
      return static_cast<int>(ans);
    }
};

int main(){
  vector<int>nums={1, 2, 3, 4, 5};
  int k=3;
  Solution obj;
  cout<<obj.splitArray(nums,k);
  return 0;
}