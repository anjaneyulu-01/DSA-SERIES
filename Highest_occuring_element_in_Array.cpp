/*
Highest Occurring Element in an Array

Easy

Given an array nums of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.



Please note that this section might seem a bit difficult without prior knowledge on what hashing is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!


Examples:
Input: nums = [1, 2, 2, 3, 3, 3]

Output: 3

Explanation: The number 3 appears the most (3 times). It is the most frequent element.

Input: nums = [4, 4, 5, 5, 6]

Output: 4

Explanation: Both 4 and 5 appear twice, but 4 is smaller. So, 4 is the most frequent element.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
 int findHighestfreq(vector<int>&nums){
  int n=nums.size();
  unordered_map<int,int>m;
   for(int val:nums){
    m[val]++;
   }
  int maxfreq=0;
  int smallest=INT_MAX;
  for(auto &it:m){
   int num=it.first;
   int freq=it.second;
   if(freq>maxfreq){
    maxfreq=freq;
    smallest=num;
   }
   else if(freq==maxfreq && num<smallest){
    smallest=num;
   }
  }
  return smallest;
 }
};

int main(){
  vector<int>nums={1,2,2,3,4,5,5,6};
  Solution obj;
  cout<<obj.findHighestfreq(nums);
  return 0;
}