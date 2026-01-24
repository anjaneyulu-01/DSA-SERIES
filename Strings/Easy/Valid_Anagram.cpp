/*
Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.



An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


Example 1

Input : s = "anagram" , t = "nagaram"

Output : true

Explanation :

We can rearrange the characters of string s to get string t as frequency of all characters from both strings is same.

Example 2

Input : s = "dog" , t = "cat"

Output : false

Explanation :

We cannot rearrange the characters of string s to get string t as frequency of all characters from both strings is not same.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  bool isvalid(string s,string t){
    if(s.length()!=t.length())return false;
    vector<int> freq(26, 0);
    for(int i=0; i<s.length(); i++){
       freq[s[i]-'a']++;
       freq[t[i]-'a']--;
    }
    for(int i=0; i<26; i++){
      if(freq[i]!=0)return false;
    }
    return true;
  }
};

int main(){
  string s="anagram";
  string t="nagaram";
  Solution obj;
  cout<<obj.isvalid(s,t);
  return 0;
}