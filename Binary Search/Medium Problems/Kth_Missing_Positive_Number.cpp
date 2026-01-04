/*
Kth Missing Positive Number
Given a sorted array of unique positive integers arr, your task is to return the kᵗʰ missing positive number that is not present in arr.



The array is guaranteed to be strictly increasing, and the missing numbers are those positive integers that do not appear in arr but would appear in a full sequence starting from 1.


Example 1

Input: arr = [3, 5, 7, 10], k = 6

Output: 9

Explanation:

The missing numbers are [1, 2, 4, 6, 8, 9, 11, ...]. The 6ᵗʰ missing number is 9.

Example 2

Input: arr = [1, 4, 6, 8, 9], k = 3

Output: 5

Explanation:

The missing numbers are [2, 3, 5, 7, 10, ...]. The 3ʳᵈ missing number is 5.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int findKthPositive(vector<int>&arr,int k){
int low=0,high=arr.size()-1;
   while(low<=high){
   int mid=low+(high-low)/2;
   int missing=arr[mid]-(mid+1);
   if(missing<k)low=mid+1;
   else high=mid-1;
   }
   return low+k;
 }
};

int main(){
  vector<int>nums={3, 5, 7, 10};
  int k=6;
  Solution obj;
  cout<<obj.findKthPositive(nums,k);
  return 0;
}
