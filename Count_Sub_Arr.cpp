/*
Count subarrays with given sum

Medium

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.


Examples:
Input: nums = [1, 1, 1], k = 2

Output: 2

Explanation: In the given array [1, 1, 1], there are two subarrays that sum up to 2: [1, 1] and [1, 1]. Hence, the output is 2.

Input: nums = [1, 2, 3], k = 3

Output: 2

Explanation: In the given array [1, 2, 3], there are two subarrays that sum up to 3: [1, 2] and [3]. Hence, the output is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
     vector<int>prefixsum(nums.size()); 
     int count=0;
     int sum=0;
      unordered_map<int,int>m;
      m[0]=1;
      for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
         int rem=sum-k;
        if(m.find(rem)!=m.end()){
            count+=m[rem];
        }
        m[sum]++;
     }
     return count;
    }
};

int main(){
  vector<int>nums={1, 2, 3};
  int k=3;
  Solution obj;
  cout<<obj.subarraySum(nums,k);
  return 0;
}