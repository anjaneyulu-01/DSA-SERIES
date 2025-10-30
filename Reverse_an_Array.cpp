/*
Reverse an array

Easy

Hints
Given an array arr of n elements. The task is to reverse the given array. The reversal of array should be inplace.


Examples:
Input: n=5, arr = [1,2,3,4,5]



Output: [5,4,3,2,1]



Explanation: The reverse of the array [1,2,3,4,5] is [5,4,3,2,1]

Input: n=6, arr = [1,2,1,1,5,1]



Output: [1,5,1,1,2,1]



Explanation: The reverse of the array [1,2,1,1,5,1] is [1,5,1,1,2,1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  void ReverseArray(int *arr,int size){
    int st=0,end=size-1;
    while(st<end){
    swap(arr[st],arr[end]);
    st++;
    end--;
  }
 }
};

int main(){
  int size=6;
  int arr[]={1,2,3,4,5,6};
  Solution obj;
  obj.ReverseArray(arr,size);
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}