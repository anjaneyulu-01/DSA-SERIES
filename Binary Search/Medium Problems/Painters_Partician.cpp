/*
You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:

Each painter paints only contiguous segments of boards.
No board can be split between painters.
The goal is to minimize the time to paint all boards.


Return the minimum time required to paint all boards modulo 10000003.


Example 1

Input: A = 2, B = 5, C = [1, 10]

Output: 50

Explanation:

Painter 1 paints board 0 (length = 1), time = 5
Painter 2 paints board 1 (length = 10), time = 50
Max time = 50
Return 50 % 10000003 = 50
Example 2

Input: A = 10, B = 1, C = [1, 8, 11, 3]

Output: 11

Explanation:

Assign each board to a different painter
Max time = max(1, 8, 11, 3) = 11
Return 11 % 10000003 = 11
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static const int MOD = 10000003;
    bool canPaint(vector<int>& C, int A, long long maxLen){
        int painters = 1;
        long long currSum = 0;

        for(int len : C){
            if(currSum + len > maxLen){
                painters++;
                currSum = len;
                if(painters > A) return false;
            }
            else{
                currSum += len;
            }
        }
        return true;
    }

    int paint(int A, int B, vector<int>& C){
        long long low = *max_element(C.begin(), C.end());
        long long high = accumulate(C.begin(), C.end(), 0LL);
        long long ans = high;

        while(low <= high){
            long long mid = (low + high) / 2;
            if(canPaint(C, A, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return (ans % MOD * B % MOD) % MOD;
    }
};

int main(){
  vector<int>nums={1, 8, 11, 3};
  int A=10,B=1;
  Solution obj;
  cout<<obj.paint(A,B,nums);
  return 0;
}