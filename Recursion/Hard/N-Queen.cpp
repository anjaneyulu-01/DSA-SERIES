/*
N Queen
The challenge of arranging n queens on a n × n chessboard so that no two queens attack one another is known as the "n-queens puzzle."



Return every unique solution to the n-queens puzzle given an integer n. The answer can be returned in any sequence.



Every solution has a unique board arrangement for the placement of the n-queens, where 'Q' and '.' stand for a queen and an empty space, respectively.


Example 1

Input : n = 4

Output : [[".Q.." , "...Q" , "Q..." , "..Q."] , ["..Q." , "Q..." , "...Q" , ".Q.."]]

Explanation : There are two possible combinations as shown below.

Example 2

Input : n = 2

Output : [ [] ]

Explanation : There is no possible combination for placing two queens on a board of size 2*2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }

        r = row; c = col;
        while (r >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
        }
        r = row; c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') return false;
            r--; c++;
        }

        return true;
    }
    void solve(int row, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);
        return ans;
    }
};

int main() {
    Solution obj; 
    int n = 4;

    vector<vector<string>> result = obj.solveNQueens(n);
    cout << "Solutions for n = " << n << ":\n";
    for (auto sol : result) {
        cout << "[\n";
        for (auto row : sol) {
            cout << "\"" << row << "\"" << endl;
        }
        cout << "]\n\n";
    }

    return 0;
}