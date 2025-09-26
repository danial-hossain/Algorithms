#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void printPath(int u, int v, vector<vector<int>> &pi) {
    if (u == v) {
        cout << u << " ";
    } else if (pi[u][v] == -1) {
        cout << "No path from " << u << " to " << v << endl;
    } else {
        printPath(u, pi[u][v], pi);
        cout << v << " ";
    }
}

void floydWarshall(int n, vector<vector<int>> &matrix) {
    vector<vector<int>> pi(n, vector<int>(n, -1));

    // Initialize pi matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && matrix[i][j] != INF)
                pi[i][j] = i;

    // Floyd-Warshall
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][k] != INF && matrix[k][j] != INF && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    pi[i][j] = pi[k][j];
                }

    // Print final distance matrix
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Optional: print one example path (e.g. 0 to 3)
    cout << "\nPath from 0 to 3: ";
    if (matrix[0][3] == INF)
        cout << "No path" << endl;
    else
        printPath(0, 3, pi);
    cout << endl;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> matrix(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
        matrix[i][i] = 0;

    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w;
    }

    floydWarshall(n, matrix);

    return 0;
}
