/*
Search in 2D matrix - II
Given a 2D array matrix where each row is sorted in ascending order from left to right and each column is sorted in ascending order from top to bottom, write an efficient algorithm to search for a specific integer target in the matrix.


Example 1

Input: matrix = [ [1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30] ], target = 5

Output: True

Explanation: The target 5 exists in the matrix in the index (1,1)

Example 2

Input: matrix= [ [1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30] ], target = 20

Output: False

Explanation: The target 20 does not exist in the matrix.
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int r = 0;
    int c = cols - 1;

    while(r < rows && c >= 0){
        if(matrix[r][c] == target)
            return true;
        else if(matrix[r][c] > target)
            c--;
        else
            r++;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix ={
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target1 = 5;
    int target2 = 20;

    cout << "Target " << target1 << ": "
         << (searchMatrix(matrix, target1) ? "True" : "False") << endl;

    cout << "Target " << target2 << ": "
         << (searchMatrix(matrix, target2) ? "True" : "False") << endl;

    return 0;
}
