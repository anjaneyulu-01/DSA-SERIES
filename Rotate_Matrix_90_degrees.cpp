/*
Rotate matrix by 90 degrees

Medium

Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.



The rotation must be done in place, meaning the input 2D matrix must be modified directly.


Examples:
Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]



Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]



Input: matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]



Output: matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};


int main(){
  vector<vector<int>>nums={{0, 1, 1, 2}, {2, 0, 3, 1}, {4, 5, 0, 5}, {5, 6, 7, 0}};
  Solution obj;
  obj.rotateMatrix(nums);
  for(int i=0; i<nums.size(); i++){
    for(int j=0; j<nums[i].size(); j++){
      cout<<nums[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}