/*
Maximum Nesting Depth of the Parentheses
A string s is a valid parentheses string (VPS) if it meets the following conditions:

It only contains digits 0-9, arithmetic operators +, -, *, /, and parentheses (, ).
The parentheses are balanced and correctly nested.


Your task is to compute the maximum nesting depth of parentheses in s. The nesting depth is the highest number of parentheses that are open at the same time at any point in the string.


Example 1

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation: The deepest nested sub-expression is ((8)/4), which has 3 layers of parentheses.



Example 2

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation: The digit '3' is enclosed in 3 pairs of parentheses.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
  public:
int maxDepth(string s){
    int currentDepth = 0;
    int maxDepth = 0;
  for(char c : s){
        if(c == '('){
            currentDepth++;
            maxDepth = max(maxDepth, currentDepth);
        } 
        else if(c == ')'){
            currentDepth--;
        }
    }

    return maxDepth;
}
};
int main(){
    string s1 = "(1+(2*3)+((8)/4))+1";
    Solution obj;
   cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.maxDepth(s1) << endl << endl;
   return 0;
}
