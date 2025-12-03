/*
Set Matrix Zeroes

Medium

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0. You must do it in place.


Examples:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]

Output: [[1,0,1],[0,0,0],[1,0,1]]

Explanation:

Element at position (1,1) is 0, so set entire row 1 and column 1 to 0.

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Explanation:

There are two zeroes: (0,0) and (0,3).

Row 0 → all elements become 0
Column 0 and column 3 → all elements become 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                firstColZero = true;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
                firstRowZero = true;
                
      for (int i = 1; i < m; i++) {
          for (int j = 1; j < n; j++) {
              if (matrix[i][j] == 0) {
                  matrix[i][0] = 0;
                  matrix[0][j] = 0;
            }
          }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
             if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
            }
        }

        if (firstRowZero)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};

int main() {
  vector<vector<int>>matrix= {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution obj;
    obj.setZeroes(matrix);

    for(int i=0; i<matrix.size(); i++){
      for(int j=0; j<matrix[i].size(); j++){
       cout<<matrix[i][j]<<" ";
      }
      cout<<endl;

    }
   return 0;
}
