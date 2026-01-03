/*
Capacity to Ship Packages Within D Days

You are given an array weights where weights[i] represents the weight of the i-th package on a conveyor belt. All the packages must be shipped in the order given from one port to another within days days.



Each day, the ship can carry a contiguous sequence of packages, as long as the total weight does not exceed its maximum capacity.



Your task is to find the minimum possible capacity of the ship so that all packages can be shipped within the given number of days.


Example 1

Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5

Output: 15

Explanation:

Minimum ship capacity = 15. One way to ship in 5 days:

Day 1: 1 + 2 + 3 + 4 + 5 = 15
Day 2: 6 + 7 = 13
Day 3: 8
Day 4: 9
Day 5: 10


No day exceeds capacity 15 and all packages are shipped in order in 5 days.

Example 2

Input: weights = [3, 2, 2, 4, 1, 4], days = 3

Output: 6

Explanation:

One possible division with capacity 6:

Day 1: 3 + 2 = 5
Day 2: 2 + 4 = 6
Day 3: 1 + 4 = 5


All packages shipped in order within 3 days.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  bool isvalid(vector<int>&nums,int mid,int days){
    int d=1,max=0;
    for(int i=0; i<nums.size(); i++){
      if(nums[i]+max<=mid){
        max+=nums[i];
      }
      else{
        d++;
        max=nums[i];
      }
    }
    return d<=days;
  }
  int find(vector<int>&nums,int days){
    int largest=INT_MIN;
    int sum=0;
    int ans=-1;
    for(int i=0; i<nums.size(); i++){
      sum+=nums[i];
      if(nums[i]>largest)largest=nums[i];
    }
    int low=largest;
    int high=sum;
    while(low<=high){
      int mid=low+(high-low)/2;
      if(isvalid(nums,mid,days)){
        ans=mid;
        high=mid-1;
      }
      else{
        low=mid+1;
      }
    }
    return ans;
  }
};

int main(){
  vector<int>nums={3, 2, 2, 4, 1, 4};
  int days=3;
  Solution obj;
  cout<<obj.find(nums,days);
  return 0;
}