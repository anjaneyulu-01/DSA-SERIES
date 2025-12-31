/*
Koko eating bananas

A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. An integer h represents the total time in hours to eat all the bananas.



Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile and does not consume any more bananas in that hour.



Determine the minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours.


Example 1

Input: n = 4, nums = [7, 15, 6, 3], h = 8

Output: 5

Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  

Example 2

Input: n = 5, nums = [25, 12, 8, 14, 19], h = 5

Output: 25

Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool canEat(vector<int>& nums, int h, int k) {
    long long hours = 0;
    for (int pile : nums) {
     hours += (pile + k - 1) / k;  // ceil(pile / k)
    }
    return hours <= h;
}
int minEatingSpeed(vector<int>& nums, int h) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;
   while (low <= high) {
        int mid = low + (high - low) / 2;
    if (canEat(nums, h, mid)) {
         ans = mid;      
         high = mid - 1; 
        } 
        else {
            low = mid + 1;   
        }
    }
    return ans;
}
};

int main(){
  vector<int>nums={25, 12, 8, 14, 19};
  int h=5;
  Solution obj;
  cout<<obj.minEatingSpeed(nums,h);
 return 0;
}