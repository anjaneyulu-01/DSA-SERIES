/*
Matrix Median

Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.


Example 1

Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ] 

Output: 5

Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5

Example 2

Input: matrix=[ [1, 3, 8], [2, 3, 4], [1, 2, 5] ] 

Output: 3

Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 8. So, median = 3
*/

#include <bits/stdc++.h>
using namespace std;

int matrixMedian(vector<vector<int>>& matrix){
    int r = matrix.size();
    int c = matrix[0].size();

    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < r; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][c - 1]);
    }

    int desired = (r * c) / 2;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int count = 0;

        for(int i = 0; i < r; i++){
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count <= desired)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main() {
    vector<vector<int>> matrix1 ={{1, 4, 9},{2, 5, 6},{3, 7, 8}};
   cout << "Median of matrix : " << matrixMedian(matrix1) << endl;
    return 0;
}
