/*
Longest Common Prefix
Easy

Company
Write a function to find the longest common prefix string amongst an array of strings.



If there is no common prefix, return an empty string "".


Example 1

Input : str = ["flowers" , "flow" , "fly", "flight" ]

Output : "fl"

Explanation :

All strings given in array contains common prefix "fl".

Example 2

Input : str = ["dog" , "cat" , "animal", "monkey" ]

Output : ""

Explanation :

There is no common prefix among the given strings in array.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    if (strs.empty()) return "";

    string prefix = strs[0];

    for(int i = 1; i < strs.size(); i++){
        while(strs[i].find(prefix) != 0){
            prefix = prefix.substr(0, prefix.length() - 1);
            if(prefix == "") return "";
        }
    }
    return prefix;
}

int main(){
    vector<string> str1 = {"flowers", "flow", "fly", "flight"};
    cout << "Output: " << longestCommonPrefix(str1) << endl;
    return 0;
}
