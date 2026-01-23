/*
Rotate String

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.



A shift on s consists of moving the leftmost character of s to the rightmost position.



For example, if s = "abcde", then it will be "bcdea" after one shift.


Example 1

Input : s = "abcde" , goal = "cdeab"

Output : true

Explanation :

After performing 2 shifts we can achieve the goal string from string s.

After first shift the string s is => bcdea

After second shift the string s is => cdeab.

Example 2

Input : s = "abcde" , goal = "adeac"

Output : false

Explanation :

Any number of shift operations cannot convert string s to string goal.
*/

#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Solution{
  public:
bool rotateString(string s, string goal){
    if(s.length() != goal.length()){
        return false;
    }
    string temp = s + s;
    return temp.find(goal) != string::npos;
}
};
int main(){
string s = "abcde";
string goal = "abcde";
Solution obj;
if(obj.rotateString(s, goal)){
    cout << "true";
}
else{
    cout << "false";
}

return 0;
}
