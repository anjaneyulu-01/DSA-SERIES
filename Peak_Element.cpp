/*
Find peak element
Given an array arr of integers. A peak element is defined as an element greater than both of its neighbors.

Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i].



Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.



Note:

As there can be many peak values, "true" is given as output if the returned index is a peak number, otherwise "false".

Example 1

Input : arr = [1, 2, 3, 4, 5, 6, 7, 8, 5, 1]

Output: 7

Explanation: In this example, there is only 1 peak that is at index 7.

Example 2

Input : arr = [1, 2, 1, 3, 5, 6, 4]

Output: 1

Explanation: In this example, there are 2 peak numbers at indices 1 and 5. We can consider any of them.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int peakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
 while (low < high) {
        int mid = low + (high - low) / 2;
   if (nums[mid] < nums[mid + 1])
       low = mid + 1;
   else
      high = mid;
    }
    return low;  
  }
};


int main(){
  vector<int>nums={1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
  Solution obj;
  cout<<obj.peakElement(nums);
  return 0;
}