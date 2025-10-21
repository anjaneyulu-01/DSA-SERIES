/*
Reverse a number


0

100
Easy

You are given an integer n. Return the integer formed by placing the digits of n in reverse order.


Examples:
Input: n = 25

Output: 52

Explanation: Reverse of 25 is 52.

Input: n = 123

Output: 321

Explanation: Reverse of 123 is 321.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  int ReverseaNumber(int number){
    int remainder=0;
    int reversednumber=0;
    while(number!=0){
      remainder=number%10;
      reversednumber=reversednumber*10+remainder;
      number=number/10;
    }
    return reversednumber;
  }
};

int main(){
  int number=563;
  Solution obj;
  cout<<obj.ReverseaNumber(number);
  return 0;
}