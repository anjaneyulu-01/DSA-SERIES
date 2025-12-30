/*
Find Nth root of a number

Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.


Example 1

Input: N = 3, M = 27

Output: 3

Explanation: The cube root of 27 is equal to 3.

Example 2

Input: N = 4, M = 69

Output:-1

Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int NthRoot(int n, int m) {
  int low = 1, high = m;

  while (low <= high) {
      int mid = low + (high - low) / 2;
      long long value = 1;
      for (int i = 1; i <= n; i++) {
          value *= mid;
          if (value > m) break;
      }
     if (value == m)
          return mid;
      else if (value > m)
          high = mid - 1;
      else
          low = mid + 1;
  }
  return -1;
}
};

int main(){
 int N = 3, M = 27;
Solution obj;
cout<<obj.NthRoot(N,M);
return 0;
}