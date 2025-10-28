/*
Sum of First N Numbers
Easy

Hints
Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.


Examples:
Input : N = 4

Output : 10

Explanation : first four natural numbers are 1, 2, 3, 4.

Sum is 1 + 2 + 3 + 4 => 10.

Input : N = 2

Output : 3

Explanation : first two natural numbers are 1, 2.

Sum is 1 + 2 => 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
 int SumofNumbers(int number){
  if(number==1){
     return 1;
  }
  return number+SumofNumbers(number-1);
 }
};

int main(){
  int number=5;
  Solution obj;
  cout<<obj.SumofNumbers(number);
  return 0;
}