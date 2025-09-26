#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites) {
        // Adjacency list creation
        vector<int> adj[N];
        vector<int> InDeg(N, 0);
        
        for (int i = 0; i < P; i++) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            InDeg[prerequisites[i].first]++;
        }

        // Kahn's Algorithm (BFS for Topological Sorting)
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (InDeg[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Look at the neighbors
            for (int j = 0; j < adj[node].size(); j++) {
                InDeg[adj[node][j]]--;
                if (InDeg[adj[node][j]] == 0) {
                    q.push(adj[node][j]);
                }
            }
        }

        return count == N;
    }
};

int main() {
    Solution sol;
    int N = 4, P = 3;
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    if (sol.isPossible(N, P, prerequisites)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    N = 2, P = 2;
    prerequisites = {{1, 0}, {0, 1}};
    if (sol.isPossible(N, P, prerequisites)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
