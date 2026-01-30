/*
Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.



A palindromic substring is a contiguous sequence of characters within the string that reads the same forward and backward.


Example 1

Input: s = "babad"

Output: "bab"

Explanation:

Both "bab" and "aba" are valid palindromic substrings of length 3. Return either.

Example 2

Input: s = "cbbd"

Output: "bb"

Explanation:

The longest palindrome is "bb" of length 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
string longestPalindrome(string s){
int n = s.size();
if (n == 0) return "";

int start = 0, maxLen = 1;

auto expand = [&](int left, int right){
  while(left >= 0 && right < n && s[left] == s[right]){
      if(right - left + 1 > maxLen){
          start = left;
          maxLen = right - left + 1;
      }
      left--;
      right++;
  }
};

for(int i = 0; i < n; i++){
  expand(i, i);
  expand(i, i + 1);
}

return s.substr(start, maxLen);
}
};

int main() {
  Solution obj;

string s1 = "babad";
cout << "Input: " << s1 << endl;
cout << "Output: " << obj.longestPalindrome(s1) << endl;
return 0;
}
