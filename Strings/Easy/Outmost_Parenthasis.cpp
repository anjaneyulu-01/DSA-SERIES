/*
Remove Outermost Parentheses
A valid parentheses string is defined by the following rules:

It is the empty string "".
If A is a valid parentheses string, then so is "(" + A + ")".
If A and B are valid parentheses strings, then A + B is also valid.


A primitive valid parentheses string is a non-empty valid string that cannot be split into two or more non-empty valid parentheses strings.



Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.



Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.


Example 1

Input: s = "((()))"

Output: "(())"

Explanation:

The input string is a single primitive: "((()))".

Removing the outermost layer yields: "(())".

Example 2

Input: s = "()(()())(())"

Output: "()()()"

Explanation:

Primitive decomposition: "()" + "(()())" + "(())"

After removing outermost parentheses: "" + "()()" + "()"

Final result: "()()()".
*/

#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s){
    string result = "";
    int balance = 0;

    for(char ch : s){
        if(ch == '('){
            if(balance > 0){
                result += ch;
            }
            balance++;
        }
        else{ 
            balance--;
            if(balance > 0){
                result += ch;
            }
        }
    }
    return result;
}

int main(){
    string s1 = "((()))";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << removeOuterParentheses(s1) << endl;

    cout << endl;

    return 0;
}
