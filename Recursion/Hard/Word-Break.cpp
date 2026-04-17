/*
Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words otherwise return false.



Note : The same word in dictionary can be used multiple times in segmentation.


Example 1

Input : s = "takeuforward" , wordDict = ["take" , "forward" , "you", "u"]

Output : true

Explanation : Return true because "takeuforward" can be segmented as "take" , "u" , "forward".

Example 2

Input : s = "applepineapple" , wordDict = ["apple"]

Output : false

Explanation : Return false because "applepineapple" can be segmented as "apple" , "pine" , "apple" but here we do not have "pine" word in dictionary.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int index, string &s, unordered_set<string> &dict, vector<int> &dp) {
        if (index == s.size()) return true;
        if (dp[index] != -1) return dp[index];

        string temp = "";

        for (int i = index; i < s.size(); i++) {
            temp += s[i];

            if (dict.find(temp) != dict.end()) {
                if (solve(i + 1, s, dict, dp)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);

        return solve(0, s, dict, dp);
    }
};

int main() {
    string s = "takeuforward";
    vector<string> wordDict = {"take", "forward", "you", "u"};
    Solution obj;

    bool result = obj.wordBreak(s, wordDict);

    if (result)
        cout << "true";
    else
        cout << "false";

    return 0;
}