/*
Find Peak Element - II

Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j].A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.



Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.



Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.


Example 1

Input: mat=[[10, 20, 15], [21, 30, 14], [7, 16, 32]]

Output: [1, 1]

Explanation: The value at index [1, 1] is 30, which is a peak element because all its neighbours are smaller or equal to it. Similarly, {2, 2} can also be picked as a peak.

Example 2

Input: mat=[[10, 7], [11, 17]]

Output : [1, 1]

Explanation:The value at index [1, 1] is 17, which is the only peak element because all its neighbours are smaller or equal to it.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int maxRow = 0;
            for(int i = 0; i < n; i++){
                if(mat[i][mid] > mat[maxRow][mid]){
                    maxRow = i;
                }
            }

            int leftVal  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;
            if(mat[maxRow][mid] > leftVal && mat[maxRow][mid] > rightVal){
                return {maxRow, mid};
            }
            else if(leftVal > mat[maxRow][mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return {-1, -1}; 
    }
};

int main(){
    Solution sol;
    vector<vector<int>> mat = {{10, 20, 15},{21, 30, 14},{7, 16, 32} };

    vector<int> peak = sol.findPeakGrid(mat);
    cout << "Peak index for Example 1: [" 
         << peak[0] << ", " << peak[1] << "]" << endl;


    return 0;
}
