#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) {
    // Create adjacency list and in-degree array
    vector<int> adj[N];
    vector<int> InDeg(N, 0);

    // Construct the graph
    for (int i = 0; i < P; i++) {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        InDeg[prerequisites[i][0]]++;
    }

    // Kahn's Algorithm (Topological Sorting)
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (InDeg[i] == 0) 
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Reduce the in-degree of neighbors
        for (int neighbor : adj[node]) {
            InDeg[neighbor]--;
            if (InDeg[neighbor] == 0) 
                q.push(neighbor);
        }
    }

    // If topological ordering is valid, return it; otherwise, return an empty array
    return ans.size() == N ? ans : vector<int>{};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<int> order = findOrder(n, m, prerequisites);

    if (order.empty()) {
        cout << "No Ordering Possible" << endl;
    } else {
        cout << "1" << endl;  // Output 1 if the order is valid
    }

    return 0;
}
