/*
Reverse every word in a string
Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ). A word is defined as a sequence of non-space characters. The words in s are separated by at least one space.



Return a string with the words in reverse order, concatenated by a single space.


Example 1

Input: s = "welcome to the jungle"



Output: "jungle the to welcome"



Explanation: The words in the input string are "welcome", "to", "the", and "jungle". Reversing the order of these words gives "jungle", "the", "to", and "welcome". The output string should have exactly one space between each word.

Example 2

Input: s = " amazing coding skills "



Output: "skills coding amazing"



Explanation: The input string has leading and trailing spaces, as well as multiple spaces between the words "amazing", "coding", and "skills". After trimming the leading and trailing spaces and reducing the multiple spaces between words to a single space, the words are "amazing", "coding", and "skills". Reversing the order of these words gives "skills", "coding", and "amazing". The output string should not have any leading or trailing spaces and should have exactly one space between each word.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string reverseWords(string s){
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result = "";
        for(int i = 0; i < words.size(); i++){
            result += words[i];
            if(i != words.size() - 1)
                result += " ";
        }
       return result;
    }
};

int main(){
Solution obj;
string s1 = "welcome to the jungle";
cout << "Input: " << s1 << endl;
cout << "Output: " << obj.reverseWords(s1) << endl;
return 0;
}
