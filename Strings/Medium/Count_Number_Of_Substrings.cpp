/*
Count Number of Substrings

Problem Statement: You are given a string s and a positive integer k.
Return the number of substrings that contain exactly k distinct characters.
*/

#include <bits/stdc++.h>
using namespace std;
long long atMostK(string &s, int k){
  if (k < 0) return 0;

  unordered_map<char, int> freq;
  int left = 0;
  long long count = 0;

  for(int right = 0; right < s.length(); right++){
      freq[s[right]]++;

      while(freq.size() > k){
          freq[s[left]]--;
          if (freq[s[left]] == 0)
              freq.erase(s[left]);
          left++;
      }

      count += (right - left + 1);
  }

  return count;
}
long long substrCount(string s, int k){
  return atMostK(s, k) - atMostK(s, k - 1);
}

int main() {
string s = "abcbaa";
int k = 2;

cout << "String: " << s << endl;
cout << "K = " << k << endl;
cout << "Substrings with exactly k distinct characters: "
      << substrCount(s, k) << endl;

return 0;
}
