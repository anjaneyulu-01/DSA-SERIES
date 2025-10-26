/*Print 1 to N using Recursion


0

100
Easy

Given an integer n, write a function to print all numbers from 1 to n (inclusive) using recursion.

You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in increasing order from 1 to n.

Examples:
Input: n = 5

Output:

1  

2  

3  

4  

5

Input: n = 1

Output:

1*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
void PrintNumbers(int number){
if(number==0){
  return;
}
PrintNumbers(number-1);
cout<<number<<"\n";
}
};

int main(){
  int number=5;
  Solution obj;
  obj.PrintNumbers(number);
  return 0;
}