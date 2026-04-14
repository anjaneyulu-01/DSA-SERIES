/*
Palindrome partitioning

Given a string s partition string s such that every substring of partition is palindrome. Return all possible palindrome partition of string s.


Example 1

Input : s = "aabaa"

Output : [ [ "a", "a", "b", "a", "a"] , [ "a", "a", "b", "aa"] , [ "a", "aba", "a"] , [ "aa", "b", "a", "a"] , [ "aa", "b", "aa" ] , [ "aabaa" ] ]

Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is a palindrome.

Example 2

Input : s = "baa"

Output : [ [ "b", "a", "a"] , [ "b", "aa" ] ]

Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;

class PalindromePartition {
public:

    bool isPalindrome(string &s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    void solve(int index, string &s, vector<string> &path, vector<vector<string>> &result) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, path, result);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        solve(0, s, path, result);
        return result;
    }
};

int main() {
    string s;
    
    cout << "Enter string: ";
    cin >> s;
    PalindromePartition obj;
    vector<vector<string>> ans = obj.partition(s);

    cout << "\nPalindrome Partitions:\n";
    for (auto &vec : ans) {
        cout << "[ ";
        for (auto &str : vec) {
            cout << "\"" << str << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}