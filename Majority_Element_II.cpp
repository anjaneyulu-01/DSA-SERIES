/*
Majority Element-II

Hard

Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.


Examples:
Input: nums = [1, 2, 1, 1, 3, 2]

Output: [1]

Explanation:

Here, n / 3 = 6 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1]

Input: nums = [1, 2, 1, 1, 3, 2, 2]

Output: [1, 2]

Explanation:

Here, n / 3 = 7 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1, 2]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        vector<int>ans;
        int count1=0,count2=0;
        int el1=INT_MIN, el2=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==el1)count1++;
            else if(nums[i]==el2)count2++;
            else if(count1==0 && el2!=nums[i]){
                count1=1;
                el1=nums[i];
            }
            else if(count2==0 && el1!=nums[i]){
                count2=1;
                el2=nums[i];
            }

            else{
                count1--;
                count2--;
            }
        }
        int num1=0,num2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==el1){
                num1++;
            }
            if(nums[i]==el2){
                num2++;
            }

        }
      if(num1>nums.size()/3)ans.push_back(el1);
      if(num2>nums.size()/3)ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
  vector<int>nums={1, 2, 1, 1, 3, 2, 2};
  Solution obj;
  vector<int>ans=obj.majorityElementTwo(nums);
  for(auto val:ans){
    cout<<val<<" ";
  }
  return 0;
}