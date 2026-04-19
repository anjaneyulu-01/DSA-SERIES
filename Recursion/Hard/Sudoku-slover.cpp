/*
Sudoku Solver
Create a program that fills in the blank cells in a Sudoku puzzle to solve it.



Every sudoku solution needs to follow to these guidelines:



1) In every row, the numbers 1 through 9 must appear exactly once.

2) In every column, the numbers 1 through 9 must appear exactly once.

3) In each of the grid's nine 3x3 sub-boxes, the numbers 1 through 9 must appear exactly once.



Empty cells are indicated by the '.' character.


Example 1

Input : board = [ ["5", "3", ".", ".", "7", ".", ".", ".", "."] , ["6", ".", ".", "1", "9", "5", ".", ".", "."] , [".", "9", "8", ".", ".", ".", ".", "6", "."] , ["8", ".", ".", ".", "6", ".", ".", ".", "3"] , ["4", ".", ".", "8", ".", "3", ".", ".", "1"] , ["7", ".", ".", ".", "2", ".", ".", ".", "6"] , [".", "6", ".", ".", ".", ".", "2", "8", "."] , [".", ".", ".", "4", "1", "9", ".", ".", "5"] , [".", ".", ".", ".", "8", ".", ".", "7", "9"] ]

Output : [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

Explanation : The Input and Output boards are shown above.

Example 2

Input : board = [ [ ".", ".", ".", ".", ".", ".", "7", ".", ".", ], [ "7", ".", "5", ".", ".", ".", "9", ".", ".", ], [ ".", ".", ".", "9", "7", "5", "4", "3", "1", ], [ "9", ".", ".", ".", "4", "1", ".", ".", "7", ], [ ".", "5", ".", "8", ".", "7", "6", "4", ".", ], [ ".", "7", ".", ".", "2", ".", ".", ".", ".", ], [ ".", "4", ".", ".", ".", ".", ".", "6", "9", ], [ "1", "6", ".", "4", "3", ".", ".", ".", ".", ], [ ".", ".", ".", ".", "6", "2", "3", ".", "4", ] ]

Output : [ [ "4", "1", "9", "3", "8", "6", "7", "5", "2", ], [ "7", "3", "5", "2", "1", "4", "9", "8", "6", ], [ "8", "2", "6", "9", "7", "5", "4", "3", "1", ], [ "9", "8", "3", "6", "4", "1", "5", "2", "7", ], [ "2", "5", "1", "8", "9", "7", "6", "4", "3", ], [ "6", "7", "4", "5", "2", "3", "1", "9", "8", ], [ "3", "4", "7", "1", "5", "8", "2", "6", "9", ], [ "1", "6", "2", "4", "3", "9", "8", "7", "5", ], [ "5", "9", "8", "7", "6", "2", "3", "1", "4", ] ]
Explanation : The Input and output board are shown above.
*/


#include <bits/stdc++.h>
using namespace std;

class SudokuSolver {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) return false;
            if (board[i][col] == num) return false;
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == num)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(board, i, j, num)) {
                            board[i][j] = num;

                            if (solve(board))
                                return true;

                      
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    SudokuSolver obj;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    obj.solveSudoku(board);
    cout << "Solved Sudoku:\n";
    for (auto &row : board) {
        for (auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}