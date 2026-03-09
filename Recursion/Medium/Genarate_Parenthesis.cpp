/*
Generate Parentheses
Given an integer n.Generate all possible combinations of well-formed parentheses of length 2 x N.


Example 1

Input : n = 3

Output : [ "((()))" , "(()())" , "(())()" , "()(())" , "()()()" ]

Example 2

Input : 2

Output : [ "(())" , "()()" ]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void generate(int open, int close, int n, string current, vector<string>& ans) {
        
        // Base condition
        if(current.length() == 2*n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if(open < n) {
            generate(open + 1, close, n, current + "(", ans);
        }

        // Add closing bracket
        if(close < open) {
            generate(open, close + 1, n, current + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0, 0, n, "", ans);
        return ans;
    }
};

int main() {

    int n = 3;   // given input
    
    Solution obj;   // object creation
    
    vector<string> result = obj.generateParenthesis(n);

    cout << "Generated Parentheses:\n";

    for(string s : result) {
        cout << s << endl;
    }

    return 0;
}