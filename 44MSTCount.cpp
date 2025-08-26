#include <bits/stdc++.h>
using namespace std;

int FindParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = FindParent(parent[u], parent);
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = FindParent(u, parent);
    int pv = FindParent(v, parent);

    if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

// --------- Kruskal’s MST cost (your original function) ----------
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            edges.push_back({adj[i][j][1], {i, adj[i][j][0]}});
        }
    }

    sort(edges.begin(), edges.end());

    int cost = 0, cnt = 0;
    for (auto &it : edges)
    {
        int wt = it.first, u = it.second.first, v = it.second.second;
        if (FindParent(u, parent) != FindParent(v, parent))
        {
            cost += wt;
            UnionByRank(u, v, parent, rank);
            cnt++;
        }
        if (cnt == V - 1) break;
    }
    return cost;
}

// --------- Matrix Tree theorem (to count spanning trees) ----------
long long determinant(vector<vector<long long>> mat, int n)
{
    long long det = 1;
    for (int i = 0; i < n; i++)
    {
        int pivot = i;
        while (pivot < n && mat[pivot][i] == 0) pivot++;
        if (pivot == n) return 0;
        if (pivot != i)
        {
            swap(mat[pivot], mat[i]);
            det = -det;
        }
        det *= mat[i][i];
        long long inv = mat[i][i];
        for (int j = i; j < n; j++) mat[i][j] /= inv;
        for (int k = i + 1; k < n; k++)
        {
            long long factor = mat[k][i];
            for (int j = i; j < n; j++)
                mat[k][j] -= factor * mat[i][j];
        }
    }
    return llabs(det);
}

long long countSpanningTrees(int V, vector<pair<int,int>> &edges)
{
    vector<vector<long long>> L(V, vector<long long>(V, 0));

    for (auto &e : edges)
    {
        int u = e.first, v = e.second;
        L[u][u]++; L[v][v]++;
        L[u][v]--; L[v][u]--;
    }

    // Delete last row and column
    vector<vector<long long>> sub(V-1, vector<long long>(V-1));
    for (int i = 0; i < V-1; i++)
        for (int j = 0; j < V-1; j++)
            sub[i][j] = L[i][j];

    return determinant(sub, V-1);
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    vector<pair<int,int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u,v});
    }

    int minCost = spanningTree(V, adj);
    long long numMST = countSpanningTrees(V, edges);

    cout << "Minimum Cost = " << minCost << endl;
    cout << "Number of MSTs = " << numMST << endl;

    return 0;
}
/*
6 7
0 1 1
0 2 1
1 3 1
2 4 1
3 5 1
4 5 1
1 2 1






*/