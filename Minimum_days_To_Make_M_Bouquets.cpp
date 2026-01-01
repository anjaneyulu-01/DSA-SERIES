/*
Minimum days to make M bouquets

Given n roses and an array nums where nums[i] denotes that the 'ith' rose will bloom on the nums[i]th day, only adjacent bloomed roses can be picked to make a bouquet. Exactly k adjacent bloomed roses are required to make a single bouquet. Find the minimum number of days required to make at least m bouquets, each containing k roses. Return -1 if it is not possible.


Example 1

Input: n = 8, nums = [7, 7, 7, 7, 13, 11, 12, 7], m = 2, k = 3

Output: 12

Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

Example 2

Input: n = 5, nums = [1, 10, 3, 10, 2], m = 3, k = 2

Output: -1

Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool canMake(vector<int>& nums, int m, int k, int day) {
int bouquets = 0, flowers = 0;
for (int i = 0; i < nums.size(); i++) {
  if (nums[i] <= day) {
      flowers++;
      if (flowers == k) {
          bouquets++;
          flowers = 0;
      }
  } 
  else {
      flowers = 0;
  }
}
return bouquets >= m;
}
int minDays(vector<int>& nums, int m, int k) {
long long n = nums.size();
if (n < (long long)m * k) return -1;
int low = *min_element(nums.begin(), nums.end());
int high = *max_element(nums.begin(), nums.end());
int ans = -1;
while (low <= high) {
  int mid = low + (high - low) / 2;
if (canMake(nums, m, k, mid)) {
      ans = mid;
      high = mid - 1;
  } else {
      low = mid + 1;
  }
}
return ans;
}
};

int main(){
  vector<int>nums={7, 7, 7, 7, 13, 11, 12, 7};
  int m = 2, k = 3;
Solution obj;
cout<<obj.minDays(nums,m,k);
return 0;
}