/*
Minimize Max Distance to Gas Station

Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.



The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.



Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.



Find the minimum value of dist.



Your answer will be accepted if it is within 1e-6 of the true value.


Example 1

Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 10

Output: 0.50000

Explanation:

One of the possible ways to place 10 gas stations is [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10].

Thus the maximum difference between adjacent gas stations is 0.5.

Hence, the value of dist is 0.5.

It can be shown that there is no possible way to add 10 gas stations in such a way that the value of dist is lower than this.

Example 2

Input : n = 10, arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 1

Output: 1.00000

Explanation:

One of the possible ways to place 1 gas station is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
New Gas Station is at 11.
Thus the maximum difference between adjacent gas stations is still 1.
Hence, the value of dist is 1.
It can be shown that there is no possible way to add 1 gas station in such a way that the value of dist is lower than this. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  bool canPlace(double dist, vector<int>& arr, int k){
        int count = 0;
   for(int i = 0; i < arr.size() - 1; i++){
            double gap = arr[i + 1] - arr[i];
            count += (int)(gap / dist);
        }

        return count <= k;
    }
   double minimizeMaxDistance(vector<int>& arr, int k){
        int n = arr.size();
        double low = 0, high = 0;
        for(int i = 0; i < n - 1; i++){
            high = max(high, (double)(arr[i + 1] - arr[i]));
        }
       double ans = high;
     while(high - low > 1e-6){
            double mid = (low + high)/2.0;
           if(canPlace(mid, arr, k)){
                ans = mid;
                high = mid;
            }
            else{
                low = mid;
            }
        }

        return ans;
    }
};

int main() {
  vector<int>nums={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k=1;
  Solution obj;
  cout<<obj.minimizeMaxDistance(nums,k);
return 0;
}
