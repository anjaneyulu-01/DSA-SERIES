/*
Finding Sqrt of a number using Binary Search
Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int SqrtNumber(int n){
    int low=0,high=n;
    while(low<=high){
      int mid=low+(high-low)/2;
      if(mid<=n/mid)low=mid+1;
      else high=mid-1;
    }
    return high;
  }
};

int main(){
  int n=16;
  Solution obj;
  cout<<obj.SqrtNumber(n);
  return 0;
}