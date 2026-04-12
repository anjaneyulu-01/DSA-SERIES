/*
Letter Combinations of a Phone Number
Given a string consisting of digits from 2 to 9 (inclusive). Return all possible letter combinations that the number can represent.



Mapping of digits to letters is given in first example.


Example 1

Input : digits = "34"

Output : [ "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi" ]

Explanation : The 3 is mapped with "def" and 4 is mapped with "ghi".

So all possible combination by replacing the digits with characters are shown in output.



Example 2

Input : digits = "3"

Output : [ "d", "e", "f" ]

Explanation : The 3 is mapped with "def".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> result;

    void solve(int index, string &digits, string &current, vector<string> &mapping) {
        // Base case
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);          // choose
            solve(index + 1, digits, current, mapping); // explore
            current.pop_back();             // backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        string current = "";
        solve(0, digits, current, mapping);

        return result;
    }
};

int main() {
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    Solution obj;  // object creation
    vector<string> ans = obj.letterCombinations(digits);

    cout << "Output:\n";
    for (string s : ans) {
        cout << s << " ";
    }

    return 0;
}