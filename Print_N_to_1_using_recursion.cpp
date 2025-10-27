/*
Print N to 1 using Recursion
Easy

Given an integer n, write a function to print all numbers from n to 1 (inclusive) using recursion.

You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in decreasing order from n to 1

Examples:
Input: 5

Output:

5

4

3

2

1

Input: 1

Output:

1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
 void PrintNumbers(int number){
  if(number<=0){
    return;
  }
  cout<<number<<"\n";
  PrintNumbers(number-1);
 }
};

int main(){
  int number=5;
  Solution obj;
  obj.PrintNumbers(number);
  return 0;
}