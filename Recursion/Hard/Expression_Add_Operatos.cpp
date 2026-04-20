/*
Expression Add Operators

Given a string num consisting of only digits and an integer target.Return all possibilities to insert the binary operators '+' , '*' , '-' between the digits of string nums, such that resultant expression evaluates to target value.


Example 1

Input : num = "123", target = 6

Output : ["1*2*3" , "1+2+3"]

Explanation :

Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2

Input : num = "0232", target = 8

Output : ["0+2*3+2" , "0+2+3*2"]

Explanation :

Both "0+2*3+2" and "0+2+3*2" evaluate to 8.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    void solve(string num, int target, int index, long long value, long long prev, string path) {
        // Base case
        if (index == num.size()) {
            if (value == target) {
                result.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.size(); i++) {
            // Avoid leading zeros
            if (i != index && num[index] == '0') break;

            string currStr = num.substr(index, i - index + 1);
            long long curr = stoll(currStr);

            if (index == 0) {
                // First number (no operator)
                solve(num, target, i + 1, curr, curr, currStr);
            } else {
                // Addition
                solve(num, target, i + 1, value + curr, curr, path + "+" + currStr);

                // Subtraction
                solve(num, target, i + 1, value - curr, -curr, path + "-" + currStr);

                // Multiplication
                solve(num, target, i + 1, value - prev + (prev * curr), prev * curr, path + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        solve(num, target, 0, 0, 0, "");
        return result;
    }
};

int main() {
    Solution obj;

    string num = "123";
    int target = 6;

    vector<string> ans = obj.addOperators(num, target);

    cout << "Valid Expressions are:\n";
    for (auto &s : ans) {
        cout << s << endl;
    }

    return 0;
}