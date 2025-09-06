#include <bits/stdc++.h>
using namespace std;

const int MIN_WEIGHT = 1;   // minimum weight >= 0
const int MAX_WEIGHT = 20;  // maximum weight

// Generate sparse directed graph
void generateSparseGraph(int V, int E, vector<vector<int>> &edges) {
    edges.clear();
    set<pair<int,int>> used;
    srand(time(0));
    while ((int)edges.size() < E) {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v) continue;               // no self-loop
        if (used.count(make_pair(u, v))) continue; // no duplicate
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        vector<int> edge;
        edge.push_back(u);
        edge.push_back(v);
        edge.push_back(w);
        edges.push_back(edge);
        used.insert(make_pair(u, v));
    }
}

// Generate dense directed graph
void generateDenseGraph(int V, vector<vector<int>> &edges) {
    edges.clear();
    set<pair<int,int>> used;
    srand(time(0));
    while ((int)edges.size() < 1225) {  // pick 1225 unique edges
        int u = rand() % V;
        int v = rand() % V;
        if (u == v) continue;               // no self-loop
        if (used.count(make_pair(u, v))) continue; // no duplicate
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        vector<int> edge;
        edge.push_back(u);
        edge.push_back(v);
        edge.push_back(w);
        edges.push_back(edge);
        used.insert(make_pair(u, v));
    }
}

int main() {
    int V = 50;
    int sparseE = 125;
    vector<vector<int>> sparseEdges, denseEdges;

    generateSparseGraph(V, sparseE, sparseEdges);
    generateDenseGraph(V, denseEdges);

    cout << "Sparse Graph edges:\n";
    for (int i = 0; i < (int)sparseEdges.size(); i++) {
        cout << sparseEdges[i][0] << " " << sparseEdges[i][1] << " " << sparseEdges[i][2] << "\n";
    }

    cout << "\nDense Graph edges:\n";
    for (int i = 0; i < (int)denseEdges.size(); i++) {
        cout << denseEdges[i][0] << " " << denseEdges[i][1] << " " << denseEdges[i][2] << "\n";
    }

    // Example: feed into Johnson algorithm
    // Johnson(V, sparseE, sparseEdges);
    // Johnson(V, denseEdges.size(), denseEdges);

    return 0;
}
