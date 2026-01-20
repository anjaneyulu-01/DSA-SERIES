/*
Largest Odd Number in a String

Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.



The number returned should not have leading zero's. But the given input string may have leading zero. (If no odd number is found, then return empty string.)


Example 1

Input : s = "5347"

Output : "5347"

Explanation :

The odd numbers formed by given strings are --> 5, 3, 53, 347, 5347.

So the largest among all the possible odd numbers for given string is 5347.

Example 2

Input : s = "0214638"

Output : "21463"

Explanation :

The different odd numbers that can be formed by the given string are --> 1, 3, 21, 63, 463, 1463, 21463.

We cannot include 021463 as the number contains leading zero.

So largest odd number in given string is 21463.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string s){
        int n = s.size();
        int idx = -1;
        for(int i = n - 1; i >= 0; i--){
            if((s[i] - '0') % 2 == 1){
                idx = i;
                break;
            }
        }
        if(idx == -1) return "";
        string ans = s.substr(0, idx + 1);
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;

        return ans.substr(i);
    }
};

int main() {
    Solution obj;
    string s1 = "5347";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.largestOddNumber(s1) << endl;
    return 0;
}
