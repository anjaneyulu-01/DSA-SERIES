/*
Maximum Consecutive Ones

Easy

Given a binary array nums, return the maximum number of consecutive 1s in the array.



A binary array is an array that contains only 0s and 1s.


Examples:
Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]

Output: 3

Explanation:

The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s

Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]

Output: 0

Explanation:

No 1s are present in nums, thus we return 0
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxsum=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                count++;
            }
            maxsum=max(count,maxsum);
            if(nums[i]!=1)count=0;
        }
        return maxsum;
    }
};

int main(){
  vector<int>nums={1, 1, 0, 0, 1, 1, 1, 0};
  Solution obj;
  cout<<obj.findMaxConsecutiveOnes(nums);
  return 0;
}