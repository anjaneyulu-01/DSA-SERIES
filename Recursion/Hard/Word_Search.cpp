/*
Word Search

Given a grid of n x m dimension grid of characters board and a string word.The word can be created by assembling the letters of successively surrounding cells, whether they are next to each other vertically or horizontally. It is forbidden to use the same letter cell more than once.

Return true if the word exists in the grid otherwise false.


Example 1

Input : board = [ ["A", "B", "C", "E"] , ["S" ,"F" ,"C" ,"S"] , ["A", "D", "E", "E"] ] , word = "ABCCED"

Output : true

Explanation : The word is coloured in yellow.

Example 2

Input : board = [["A", "B", "C", "E"] , ["S", "F", "C", "S"] , ["A", "D", "E", "E"]] , word = "SEE"

Output : true

Explanation : The word is coloured in yellow.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i+1, j, k+1) ||
                     dfs(board, word, i-1, j, k+1) ||
                     dfs(board, word, i, j+1, k+1) ||
                     dfs(board, word, i, j-1, k+1);

        board[i][j] = temp;

        return found;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";
    Solution obj;
    bool result = obj.exist(board, word);
    if(result)
        cout << "true";
    else
        cout << "false";

    return 0;
}