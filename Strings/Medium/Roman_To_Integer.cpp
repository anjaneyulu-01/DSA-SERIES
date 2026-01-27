/*
Roman to Integer
Roman numerals are represented by seven different symbols:

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000


Roman numerals are typically written from largest to smallest, left to right. However, in specific cases, a smaller numeral placed before a larger one indicates subtraction.



The following subtractive combinations are valid:

I before V (5) and X (10) → 4 and 9
X before L (50) and C (100) → 40 and 90
C before D (500) and M (1000) → 400 and 900


Given a Roman numeral, convert it to an integer.


Example 1

Input: s = "III"

Output: 3

Explanation: III = 1 + 1 + 1 = 3

Example 2

Input: s = "XLII"

Output: 42

Explanation: XL = 40, II = 2 → 40 + 2 = 42
*/

#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s){
    unordered_map<char, int> value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;

    for(int i = 0; i < s.length(); i++){
        if(i + 1 < s.length() && value[s[i]] < value[s[i + 1]]){
            result -= value[s[i]];
        }
        else{
            result += value[s[i]];
        }
    }

    return result;
}

int main(){
    string s1 = "III";
  cout << "Input: " << s1 << endl;
    cout << "Output: " << romanToInt(s1) << endl << endl;
   return 0;
}
