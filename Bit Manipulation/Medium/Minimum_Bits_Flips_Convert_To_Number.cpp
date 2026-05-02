/*
Minimum Bit Flips to Convert Number
Given two integers start and goal. Flip the minimum number of bits of start integer to convert it into goal integer.



A bits flip in the number val is to choose any bit in binary representation of val and flipping it from either 0 to 1 or 1 to 0.


Example 1

Input : start = 10 , goal = 7

Output : 3

Explanation : The binary representation of 10 is "1010".

The binary representation of 7 is "111".

If we flip the underlined bits in binary representation of 10 then we will obtain our goal.

Example 2

Input : start = 3 , goal = 4

Output : 3

Explanation : The binary representation of 3 is "011".

The binary representation of 4 is "100".

So if we flip all the three bits of 3 then we will reach our goal number.
*/


#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal; 
        int count = 0;
        while (x > 0) {
            count += (x & 1);
            x = x >> 1;
        }

        return count;
    }
};

int main() {
    Solution obj;  

    int start = 10;
    int goal = 7;

    int result = obj.minBitFlips(start, goal);

    cout << "Minimum bit flips required: " << result << endl;

    return 0;
}