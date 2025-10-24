/*
Divisors of a Number

Easy

You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.



A number which completely divides another number is called it's divisor.


Examples:
Input: n = 6

Output = [1, 2, 3, 6]

Explanation: The divisors of 6 are 1, 2, 3, 6.

Input: n = 8

Output: [1, 2, 4, 8]

Explanation: The divisors of 8 are 1, 2, 4, 8.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  vector<int> divisors(int number){
    vector<int>ans;
    int sq=sqrt(number);
    for(int i=1; i<=sq; i++){
      if(number%i==0){
       ans.push_back(i);
       if((i!=(number/i)))ans.push_back(number/i);
      }
    }
    sort(ans.begin(),ans.end());
    return ans;
  }
};

int main(){
  int number=20;
  Solution obj;
  vector<int>ans=obj.divisors(number);
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}