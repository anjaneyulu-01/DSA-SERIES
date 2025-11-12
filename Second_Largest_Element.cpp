/*
Second Largest Element

Easy

Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.


Examples:
Input: nums = [8, 8, 7, 6, 5]

Output: 7

Explanation:

The largest value in nums is 8, the second largest is 7

Input: nums = [10, 10, 10, 10, 10]

Output: -1

Explanation:

The only value in nums is 10, so there is no second largest value, thus -1 is returned
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int SecondLargest(vector<int>&nums){
    int largest=INT_MIN;
    int Slargest=INT_MIN;
    for(int i=0; i<nums.size(); i++){
      if(nums[i]>largest){
        Slargest=largest;
        largest=nums[i];
      }
      else if(nums[i]<largest && nums[i]>Slargest){
        Slargest=nums[i];
      }
    }
    if(Slargest==INT_MIN)return -1;
    return Slargest;
  }
};

int main(){
  vector<int>nums={1,2,3,4,6};
  Solution obj;
  cout<<obj.SecondLargest(nums);
  return 0;
}