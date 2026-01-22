/*
Isomorphic String

Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.



All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1

Input : s = "egg" , t = "add"

Output : true

Explanation :

The 'e' in string s can be replaced with 'a' of string t.

The 'g' in string s can be replaced with 'd' of t.

Hence all characters in s can be replaced to get t.

Example 2

Input : s = "apple" , t = "bbnbm"

Output : false

Explanation :

Strings are matched index by index.

At index 0, 'a' maps to 'b'.

At index 1, 'p' also maps to 'b'.

This is invalid because two different characters (a and p) cannot map to the same character (b) in a one-to-one mapping.

Therefore, no valid mapping exists and the output is false
*/

#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t){
    if(s.length() != t.length())
        return false;

    unordered_map<char, char> mp1; 
    unordered_map<char, char> mp2; 

    for(int i = 0; i < s.length(); i++){
        char c1 = s[i];
        char c2 = t[i];

        if(mp1.count(c1) && mp1[c1] != c2)
            return false;
        if(mp2.count(c2) && mp2[c2] != c1)
            return false;

        mp1[c1] = c2;
        mp2[c2] = c1;
    }
    return true;
}

int main() {
    string s1 = "egg";
    string t1 = "add";
    cout<< (isIsomorphic(s1, t1) ? "true" : "false") << endl;

    return 0;
}
