#include <bits/stdc++.h>
using namespace std;

#define N 100

int n, m;
int pathCount[N][N];

void floydPathCount() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                pathCount[i][j] += pathCount[i][k] * pathCount[k][j];
}

int main() {
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Initialize to 0
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            pathCount[i][j] = 0;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        pathCount[u][v] += 1;  // <-- FIXED to allow multi-edges
    }

    floydPathCount();

    cout << "\nNumber of paths between all pairs:\n";
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j && pathCount[i][j] > 0)
                cout << "From " << i << " to " << j << " = " << pathCount[i][j] << " path(s)\n";

    return 0;
}
/*
Enter number of nodes and edges: 3 5
Enter edges (u v):
1 2
1 2
2 3
2 3
1 3

Number of paths between all pairs:
From 1 to 2 = 2 path(s)
From 1 to 3 = 5 path(s)
From 2 to 3 = 2 path(s)
PS C:\Coding\C\graph> 
*/