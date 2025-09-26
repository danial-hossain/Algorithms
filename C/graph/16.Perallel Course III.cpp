#include <bits/stdc++.h>
using namespace std;

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    // Create an adjacency list
    vector<int> adj[n];

    for(int i = 0; i < relations.size(); i++) {
        // Convert them into 0-based indexing
        adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
    }

    vector<int> InDeg(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            InDeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(!InDeg[i]) q.push(i);
    }

    // Maximum time to complete previous courses
    vector<int> CourseTime(n, 0);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int j = 0; j < adj[node].size(); j++) {
            InDeg[adj[node][j]]--;
            if(!InDeg[adj[node][j]]) q.push(adj[node][j]);

            // Maximum Time to Complete Previous Course + Current Course Time
            CourseTime[adj[node][j]] = max(CourseTime[adj[node][j]], CourseTime[node] + time[node]);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, CourseTime[i] + time[i]);
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> relations = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> time = {1, 2, 3, 4, 5};

    cout << minimumTime(n, relations, time) << endl; // Output: 12

    return 0;
}
