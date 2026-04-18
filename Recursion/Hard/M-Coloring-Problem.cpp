/*
M Coloring Problem
Given an integer M and an undirected graph with N vertices (zero indexed) and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.



In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.


Example 1

Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]

Output : true

Explanation : Consider the three colors to be red, green, blue.

We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.

In this way we can color graph using 3 colors at most.



Example 2

Input : N = 3 , M = 2 , E = 3 , Edges = [ (0, 1) , (1, 2) , (0, 2) ]

Output : false

Explanation : Consider the two colors to be red, green.

We can color the vertex 0 with red, vertex 1 with green.

As the vertex 2 is adjacent to both vertex 1 and 0 , so we cannot color with red and green.

Hence as we could not color all vertex of graph we return false.


*/

#include <bits/stdc++.h>
using namespace std;

class GraphColoring {
public:
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& graph, int n, int col) {
        for (int k = 0; k < n; k++) {
            if (graph[node][k] == 1 && color[k] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, vector<int>& color, int m, int n, vector<vector<int>>& graph) {
        if (node == n) return true;

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, graph, n, col)) {
                color[node] = col;

                if (solve(node + 1, color, m, n, graph))
                    return true;

                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool graphColoring(vector<vector<int>>& graph, int m, int n) {
        vector<int> color(n, 0);
        return solve(0, color, m, n, graph);
    }
};

int main() {
    GraphColoring obj;
    int N = 4, M = 3, E = 5;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    vector<pair<int,int>> edges = {
        {0,1}, {1,2}, {2,3}, {3,0}, {0,2}
    };
    for (auto &e : edges) {
        graph[e.first][e.second] = 1;
        graph[e.second][e.first] = 1;
    }

    if (obj.graphColoring(graph, M, N))
        cout << "true";
    else
        cout << "false";

    return 0;
}