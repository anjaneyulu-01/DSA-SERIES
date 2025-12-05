/*
Print the matrix in spiral manner


0

100
Medium

Given an M * N matrix, print the elements in a clockwise spiral manner.



Return an array with the elements in the order of their appearance when printed in a spiral manner.


Examples:
Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]

Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]

Explanation:

The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5

Input: matrix = [[1, 2, 3, 4], [5, 6, 7, 8]]

Output: [1, 2, 3, 4, 8, 7, 6, 5]

Explanation:

The elements in the spiral order are 1, 2, 3, 4 -> 8, 7, 6, 5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& arr) {
      vector<int>ans;
      int scol=0, ecol=arr[0].size()-1;
      int srow=0, erow=arr.size()-1;

      while(scol<=ecol && srow<=erow){
          for(int i=scol; i<=ecol; i++)
              ans.push_back(arr[srow][i]);

          for(int j=srow+1; j<=erow; j++)
              ans.push_back(arr[j][ecol]);

          if(srow < erow){
              for(int i=ecol-1; i>=scol; i--)
                  ans.push_back(arr[erow][i]);
          }

          if(scol < ecol){
              for(int j=erow-1; j>srow; j--)
                  ans.push_back(arr[j][scol]);
          }

          srow++; erow--; scol++; ecol--;
      }

      return ans;
  }
};


int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;
    vector<int> output = obj.spiralOrder(arr);
    for(int x : output) cout << x << " ";

    return 0;
}



