/*
Pow(x,n)
Implement the power function pow(x, n) , which calculates the x raised to n i.e. xn.



Note : In output print 4 digits places after decimal point.


Example 1

Input : x = 2.0000 , n = 10

Output : 1024.0000

Explanation : Answer = 2^10 => 1024.

Example 2

Input : x = 2.0000 , n = -2

Output : 0.2500

Explanation : Answer = 2^(-2) = 1/4 => 0.25.

give the answer with the main function and with classes and with the objects and with above one input 
*/
#include <iostream>
#include <iomanip>
using namespace std;

class Solution{
public:
    double myPow(double x, int n){
        long long N = n;
        double ans = 1.0;

        if(N < 0){
            x = 1 / x;
            N = -N;
        }

        while(N > 0){
            if(N % 2 == 1){
                ans = ans * x;
            }
            x = x * x;
            N = N / 2;
        }

        return ans;
    }
};

int main(){
    double x = 2.0000;
    int n = -2;

    Solution obj;
    double result = obj.myPow(x, n);

    cout << fixed << setprecision(4);
    cout << result << endl;

    return 0;
}