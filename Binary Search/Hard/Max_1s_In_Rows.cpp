/*

Find the row with maximum number of 1's

Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1
*/

#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    int maxOnes = 0;
    int rowIndex = -1;

    for(int i = 0; i < n; i++){
        int low = 0, high = m - 1;
        int firstOne = m;
        while (low <= high){
            int mid = (low + high) / 2;
            if(mat[i][mid] == 1){
                firstOne = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        int onesCount = m - firstOne;
        if(onesCount > maxOnes){
            maxOnes = onesCount;
            rowIndex = i;
        }
    }

    return rowIndex;
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    int result = rowWithMax1s(mat);
    cout << "Row with maximum number of 1s: " << result << endl;

    return 0;
}
