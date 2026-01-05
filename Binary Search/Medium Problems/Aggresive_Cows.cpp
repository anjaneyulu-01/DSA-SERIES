/*
Aggressive Cows

Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.


Example 1

Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

Output: 3

Explanation:

The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.

In no manner can we increase the minimum distance beyond 3.

Example 2

Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]

Output: 5

Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions [1, 6]. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool canPlace(vector<int>& stalls, int k, int dist) {
  int cows = 1;             
  int lastPos = stalls[0];
  for(int i = 1; i < stalls.size(); i++){
      if(stalls[i] - lastPos >= dist){
          cows++;
          lastPos = stalls[i];
      }
      if(cows >= k) return true;
  }
  return false;
}

int aggressiveCows(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  int low = 0;
  int high = nums.back() - nums.front();
  int ans = 0;
  while(low <= high) {
      int mid = low + (high - low) / 2;
     if(canPlace(nums, k, mid)) {
          ans = mid;        
          low = mid + 1;
      }
      else{
          high = mid - 1;    
      }
  }
  return ans;
}
};

int main(){
  vector<int>nums={4, 2, 1, 3, 6};
  int k=2;
  Solution obj;
  cout<<obj.aggressiveCows(nums,k);
  return 0;
}