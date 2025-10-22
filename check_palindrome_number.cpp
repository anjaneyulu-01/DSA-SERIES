/*
Palindrome Number


0

100
Easy

You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.



A palindrome number is a number which reads the same both left to right and right to left.


Examples:
Input: n = 121

Output: true

Explanation: When read from left to right : 121.

When read from right to left : 121.

Input: n = 123

Output: false

Explanation: When read from left to right : 123.

When read from right to left : 321.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
bool ispalindrome(int N){
  int number=N;
  int remainder=0;
  int num=0;
  while(number!=0){
    remainder=number%10;
    num=num*10+remainder;
    number=number/10;
  }
  return num==N;
}
};

int main(){
  int N=123321;
  Solution obj;
  cout<<obj.ispalindrome(N);
  return 0;
}