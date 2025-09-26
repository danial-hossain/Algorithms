#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Replace -1 with INT_MAX to represent infinity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Replace INT_MAX back to -1 to indicate no path
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INT_MAX)
                matrix[i][j] = -1;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    // Initialize adjacency matrix with -1 for no edges and 0 for self-loops
    vector<vector<int>> matrix(V, vector<int>(V, -1));
    for (int i = 0; i < V; i++)
        matrix[i][i] = 0;

    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w; // directed graph; add `matrix[v][u] = w;` for undirected
    }

    shortest_distance(matrix);

    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == -1)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
