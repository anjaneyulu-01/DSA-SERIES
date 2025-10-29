/*
Given an integer n, find the factorial of n using recursion.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long factorial(int n) {
        // Base case
        if (n == 0 || n == 1)
            return 1;

        // Recursive case
        return n * factorial(n - 1);
    }
};

int main(){
  int n=5;
  Solution obj;
  cout<<obj.factorial(n);
  return 0;
}

