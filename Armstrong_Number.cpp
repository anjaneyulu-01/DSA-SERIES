/*Check if the Number is Armstrong


0

100
Easy

You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.



An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.


Examples:
Input: n = 153

Output: true

Explanation: Number of digits : 3.

13 + 53 + 33 = 1 + 125 + 27 = 153.

Therefore, it is an Armstrong number.

Input: n = 12

Output: false

Explanation: Number of digits : 2.

12 + 22 = 1 + 4 = 5.

Therefore, it is not an Armstrong number.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:

    bool ArmstrongNumber(int number){
      int temp=number;
      int digits=0;
      while(temp!=0){
        digits++;
        temp=temp/10;
      }

      temp=number;
      int remainder=0;
      int sum=0;
      while(temp!=0){
       remainder=temp%10;
       sum+=pow(remainder,digits);
       temp=temp/10;
      }
      return sum==number;
    }
    
  };

  int main(){
    int number=153;
    Solution obj;
    cout<<obj.ArmstrongNumber(number);
    return 0;
  }