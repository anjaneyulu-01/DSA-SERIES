/*
Find out how many times the array is rotated
Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.


Example 1

Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

Output: 4

Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

Example 2

Input: nums = [3, 4, 5, 1, 2]

Output: 3

Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int findRotationCount(vector<int>& nums) {
  int low = 0, high = nums.size() - 1;

  while (low < high) {
      int mid = low + (high - low) / 2;
   if (nums[mid] > nums[high]) {
          low = mid + 1;
      } else {
          high = mid;
      }
  }
  return low;
}
};

int main() {
vector<int> nums = {3, 4, 5, 1, 2};
Solution obj;
cout << obj.findRotationCount(nums);
return 0;
}
