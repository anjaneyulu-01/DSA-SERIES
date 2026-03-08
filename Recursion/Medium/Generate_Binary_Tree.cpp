/*
Generate Binary Strings Without Consecutive 1s

Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.



A binary string is a string consisting only of characters '0' and '1'.


Example 1

Input: n = 3

Output: ["000", "001", "010", "100", "101"]

Explanation: All strings are of length 3 and do not contain consecutive 1s.

Example 2

Input: n = 2

Output: ["00", "01", "10"]

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BinaryStrings {
public:

    // Recursive function to generate strings
    void generate(int n, string current, vector<string> &result) {

        // Base case
        if(current.length() == n) {
            result.push_back(current);
            return;
        }

        // Add '0'
        generate(n, current + "0", result);

        // Add '1' only if previous is not '1'
        if(current.empty() || current.back() != '1') {
            generate(n, current + "1", result);
        }
    }

    // Function to start generation
    vector<string> generateBinaryStrings(int n) {
        vector<string> result;
        generate(n, "", result);
        return result;
    }
};

int main() {

    int n;
    cout << "Enter value of n: ";
    cin >> n;

    // Create object
    BinaryStrings obj;

    // Function call
    vector<string> ans = obj.generateBinaryStrings(n);

    cout << "Binary Strings without consecutive 1s:\n";

    for(string s : ans) {
        cout << s << endl;
    }

    return 0;
}