/*
Count primes in range L to R
You are given an 2D array queries of dimension n*2.

The queries[i] represents a range from queries[i][0] to queries[i][1] (include the end points).

Return the count of prime numbers present in between each range in queries array.


Example 1

Input : queries = [ [2, 5], [4, 7] ]

Output : [3, 2]

Explanation : The range 2 to 5 contains three prime numbers 2, 3, 5.

The range 4 to 7 contains two prime numbers 5, 7.

Example 2

Input : queries = [ [1, 7], [3, 7] ]

Output : [4, 3]

Explanation : The range 1 to 7 contains four prime numbers 2, 3, 5, 7.

The range 3 to 7 contains three prime numbers 3, 5, 7.


give the answer with the main function and with classes and with the objects and with above one input function

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countPrimes(int L, int R) {

        vector<bool> prime(R + 1, true);

        prime[0] = prime[1] = false;

        for(int i = 2; i * i <= R; i++) {

            if(prime[i]) {

                for(int j = i * i; j <= R; j += i) {
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        for(int i = L; i <= R; i++) {
            if(prime[i]) {
                count++;
            }
        }

        return count;
    }
};

int main() {

    int L, R;
    cin >> L >> R;

    Solution obj;

    cout << obj.countPrimes(L, R);

    return 0;
}