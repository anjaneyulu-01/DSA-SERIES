/*
Rat in a Maze
Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).



Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).



The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.



Note :

In a path no cell can be visited more than once.
If there is no possible path then return empty vector.

Example 1

Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]

Output : [ "DDRDRR" , "DRDDRR" ]

Explanation : The rat has two different path to reach (3, 3).

The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).

The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

Example 2

Input : n = 2 , grid = [ [1, 0] , [1, 0] ]

Output : -1

Explanation : There is no path that rat can choose to travel from (0,0) to (1,1).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int i, int j, vector<vector<int>> &m, int n, 
               vector<string> &ans, string path, 
               vector<vector<int>> &visited) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }
        if (i + 1 < n && !visited[i + 1][j] && m[i + 1][j] == 1) {
            visited[i][j] = 1;
            solve(i + 1, j, m, n, ans, path + 'D', visited);
            visited[i][j] = 0;
        }
        if (j - 1 >= 0 && !visited[i][j - 1] && m[i][j - 1] == 1) {
            visited[i][j] = 1;
            solve(i, j - 1, m, n, ans, path + 'L', visited);
            visited[i][j] = 0;
        }

        if (j + 1 < n && !visited[i][j + 1] && m[i][j + 1] == 1) {
            visited[i][j] = 1;
            solve(i, j + 1, m, n, ans, path + 'R', visited);
            visited[i][j] = 0;
        }

        if (i - 1 >= 0 && !visited[i - 1][j] && m[i - 1][j] == 1) {
            visited[i][j] = 1;
            solve(i - 1, j, m, n, ans, path + 'U', visited);
            visited[i][j] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if (m[0][0] == 0) return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        solve(0, 0, m, n, ans, "", visited);

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    int n = 4;

    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    Solution obj;

    vector<string> result = obj.findPath(grid, n);
    if (result.size() == 0) {
        cout << -1 << endl;
    } else {
        for (auto path : result) {
            cout << path << " ";
        }
    }

    return 0;
}