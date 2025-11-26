/*
Majority Element-I

Easy

Given an integer array nums of size n, return the majority element of the array.



The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.


Examples:
Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]

Output: 7

Explanation:

The number 7 appears 5 times in the 9 sized array

Input: nums = [1, 1, 1, 2, 1, 2]

Output: 1

Explanation:

The number 1 appears 4 times in the 6 sized array
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MajorityElement(vector<int>& nums) {
        int freq=0,ans=0;
        for(int i=0; i<nums.size(); i++){
            if(freq==0){
                ans=nums[i];
                freq=1;
            }
            else if(ans==nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        return ans;
    }
};

int main(){
  vector<int>nums={1, 1, 1, 2, 1, 2};
  Solution obj;
  cout<<obj.MajorityElement(nums);
  return 0;
}