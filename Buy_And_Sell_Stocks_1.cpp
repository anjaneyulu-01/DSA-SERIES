/*
Best time to buy and sell stock

Medium

Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock at most once. 



The stock should be purchased before selling it, and both actions cannot occur on the same day.


Examples:
Input: arr = [10, 7, 5, 8, 11, 9]

Output: 6

Explanation: Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit = 11 - 5 = 6.

Input: arr = [5, 4, 3, 2, 1]

Output: 0

Explanation: In this case, no transactions are made. Therefore, the maximum profit remains 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int BuyAndSellStocks(vector<int>&nums){
    int bestbuy=nums[0];
    int maxprofit=0;
    int currprofit=0;
    for(int i=0; i<nums.size(); i++){
      if(nums[i]>bestbuy){
        currprofit=nums[i]-bestbuy;
        maxprofit=max(maxprofit,currprofit);
      }
      bestbuy=min(bestbuy,nums[i]);
    }
    return maxprofit;
  }
};

int main(){
  vector<int>nums={5, 4, 3, 2, 1};
  Solution obj;
  cout<<obj.BuyAndSellStocks(nums);
  return 0;
}