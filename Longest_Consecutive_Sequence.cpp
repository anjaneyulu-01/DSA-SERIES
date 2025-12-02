/*
Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Examples:
Input: nums = [100, 4, 200, 1, 3, 2]

Output: 4

Explanation:

The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

Output: 9

Explanation:

The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int Longest_Sequence(vector<int>& nums) {
    if (nums.empty()) return 0;

    set<int> s(nums.begin(), nums.end());
    auto it = s.begin();
    int prev = *it;
    int currCount = 1;
    int maxCount = 1;
    ++it;

  for (; it != s.end(); ++it) {
      if (*it == prev + 1) {
          ++currCount;
      } else {
          currCount = 1; 
      }
      prev = *it;
      maxCount = max(maxCount, currCount);
  }
  return maxCount;
}
};

int main() {
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution obj;
    cout << obj.Longest_Sequence(nums) << endl; 
    return 0;
}
