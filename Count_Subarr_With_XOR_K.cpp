/*
Count subarrays with given xor K

Hard

Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.


Examples:
Input : nums = [4, 2, 2, 6, 4], k = 6



Output : 4



Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

Input :nums = [5, 6, 7, 8, 9], k = 5



Output : 2



Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int,int>m;
        int xr=0;
        m[xr]=1;
        int count=0;
        for(int i=0; i<nums.size(); i++){
          xr=xr^nums[i];
          int x=xr^k;
          if(m.find(x)!=m.end()){
            count+=m[x];
          }
          m[xr]++;
        }
        return count;
    }
};

int main(){
  vector<int>nums={5, 6, 7, 8, 9};
  int  k = 5;
  Solution obj;
  cout<<obj.subarraysWithXorK(nums,k);
  return 0;
}