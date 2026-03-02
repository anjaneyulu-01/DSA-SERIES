/*
String to Integer (atoi)
Implement the function myAtoi(s) which converts the given string s to a 32-bit signed integer (similar to the C/C++ atoi function).



Steps to Implement:

First, ignore any leading whitespace characters ' ' until the first non-whitespace character is found.
Check the next character to determine the sign. If it’s a '-', the number should be negative. If it’s a '+', the number should be positive. If neither is found, assume the number is positive.
Read the digits and convert them into a number. Stop reading once a non-digit character is encountered or the end of the string is reached. Leading zeros should be ignored during conversion.
The result should be clamped within the 32-bit signed integer range: [-2147483648, 2147483647]. If the computed number is outside this range, return -2147483648 if the number is less than -2147483648, or return 2147483647 if the number is greater than 2147483647.
Finally, return the computed number after applying all the above steps.

Example 1

Input: s = " -12345"

Output: -12345

Explanation:

Ignore leading whitespaces.
The sign '-' is encountered, indicating the number is negative.
Digits 12345 are read and converted to -12345.
Example 2

Input: s = "4193 with words"

Output: 4193

Explanation:

Read the digits 4193 and stop when encountering the first non-digit character (w).
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution{
public:
    int myAtoi(string s){
        
        int i = 0;
        int n = s.length();
        while(i < n && s[i] == ' '){
            i++;
        }
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        long result = 0;
        
        while(i < n && isdigit(s[i])){
            
            int digit = s[i] - '0';
            if(result > INT_MAX / 10 || 
               (result == INT_MAX / 10 && digit > 7)){
                
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return (int)(sign * result);
    }
};

int main(){
    
    Solution obj;
    
    string input = "-12345";
    
    int result = obj.myAtoi(input);
    
    cout << "Converted Integer: " << result << endl;
    
    return 0;
}