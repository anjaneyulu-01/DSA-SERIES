/*
Check if String is Palindrome or Not
Easy

Given a string s, return true if the string is palindrome, otherwise false.



A string is called palindrome if it reads the same forward and backward.


Examples:
Input : s = "hannah"

Output : true

Explanation : The string when reversed is --> "hannah", which is same as original string , so we return true.

Input : s = "aabbaaa"

Output : false

Explanation : The string when reversed is --> "aaabbaa", which is not same as original string, So we return false.
*/

#include<bits/stdc++.h>
using namespace std;

class solution{
  public:
 bool recursive(string s,int st,int end){
  if(st>=end)return true;
  if(s[st]!=s[end])return false;
  return recursive(s,st+1,end-1);
 }

};

int main(){
  string s="madam";
  solution obj;
  cout<<obj.recursive(s,0,s.length()-1);
  return 0;
}