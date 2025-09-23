#include <windows.h>
#include <psapi.h>
#include <bits/stdc++.h>
#pragma comment(lib, "Psapi.lib")

#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62

const int INF = 1e9;
const int MIN_WEIGHT = 1;
const int MAX_WEIGHT = 100;

using namespace std;

// ---------------- Prim's Algorithm ----------------

int Prims2(int V, vector<vector<pair<int,int>>> &adj){
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    key[0] = 0;
    int cost = 0;

    for(int i=0;i<V;i++){
        int u=-1;
        for(int j=0;j<V;j++){
            if(!inMST[j] && (u==-1 || key[j]<key[u])) u=j;
        }
        inMST[u] = true;
        cost += key[u];

        for(int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            int w = adj[u][j].second;
            if(!inMST[v] && w < key[v]){
                key[v] = w;
            }
        }
    }
    return cost;
}


int Prims(int V, vector<vector<pair<int,int>>> &adj,bool sparse) {
    if(sparse){
   // Priority queue -> {weight, {node, parent}}
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>
        pq;
        //for one pair-->got get --> top.first()
        //for pair inside pair -->top.second.first
        //structure{Weight,Node,Parent}

    vector<bool> IsMST(V, 0);
    vector<int> parent(V, -1);

    int cost = 0;
    pq.push({0, {0, -1}}); // {weight, {node, parent}}

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();

        if (!IsMST[node])
        {
            IsMST[node] = 1;
            cost += wt;
            parent[node] = par;

            for (int j = 0; j < adj[node].size(); j++)
            {
                int adjNode = adj[node][j].first;
                int edgeWt = adj[node][j].second;

                if (!IsMST[adjNode])
                {
                    pq.push({edgeWt, {adjNode, node}});
                }
            }
        }
    }

    return cost;
    }
    else {
               vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    key[0] = 0;
    int cost = 0;

    for(int i=0;i<V;i++){
        int u=-1;
        for(int j=0;j<V;j++){
            if(!inMST[j] && (u==-1 || key[j]<key[u])) u=j;
        }
        inMST[u] = true;
        cost += key[u];

        for(int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            int w = adj[u][j].second;
            if(!inMST[v] && w < key[v]){
                key[v] = w;
            }
        }
    }
    return cost;

    }
}


// ---------------- Kruskal's Algorithm ----------------
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
    {
        parent[pu] = pv;
    }
    else if (rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int Kruskal(int V, vector<vector<int>> &edges)
{
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;



    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (auto &e : edges)
    {
        pq.push({e[2], {e[0], e[1]}});
    }

    int cost = 0, edgeCount = 0;
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if (FindParent(u, parent) != FindParent(v, parent))
        {
            cost += wt;
            UnionByRank(u, v, parent, rank);
            edgeCount++;
        }
        if (edgeCount == V - 1)
            break;
    }
    return cost;
}

// ---------------- Graph Generators ----------------
void generateSparseGraph(int V, int E, vector<vector<int>> &edges)
{
    edges.clear();
    set<pair<int, int>> used;
    srand(time(0));
    while ((int)edges.size() < E)
    {
        int u = rand() % V, v = rand() % V;
        if (u == v || used.count(make_pair(u, v)) || used.count(make_pair(v, u)))
            continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        vector<int> e;
        e.push_back(u);
        e.push_back(v);
        e.push_back(w);
        edges.push_back(e);
        used.insert(make_pair(u, v));
    }
}

void generateDenseGraph(int V, vector<vector<int>> &edges)
{
    edges.clear();
    set<pair<int,int>> used;
    srand(time(0));
    int totalEdges = V * (V-1) / 2;
    while ((int)edges.size() < totalEdges)
    {
        int u = rand() % V, v = rand() % V;
        if(u == v || used.count({u,v}) || used.count({v,u})) continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        edges.push_back({u, v, w});
        used.insert({u,v});
    }
}


// ---------------- Performance Measurement ----------------
void PerformanceMeasure(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq)
{
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy = CPU_POWER_WATTS * elapsed;
    double energy_kWh = energy / 3.6e6;
    double co2 = energy_kWh * BD_EMISSION_FACTOR;

    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc)))
    {
        SIZE_T peakMemUsed = pmc.PeakWorkingSetSize;
        cout << elapsed << "           | " << energy << "    | " << peakMemUsed << "      | " << co2;
    }
    else
    {
        printf("Failed to get memory info.\n");
    }
}

// ----------------- Main -----------------
int main()
{
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Algorithm      | Graph Type| Nodes | Edges | Execution Time(s)   | Energy(J)   | Peak Memory(KB) | CO2 Emissions (kg,BD)" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    int V = 50, sparseE = 125;
    vector<vector<int>> sparseEdges, denseEdges;
    generateSparseGraph(V, sparseE, sparseEdges);
    generateDenseGraph(V, denseEdges);

    // Build adjacency lists
    vector<vector<pair<int, int>>> sparseAdj(V), denseAdj(V);
    for (int i = 0; i < sparseEdges.size(); i++)
    {
        int u = sparseEdges[i][0], v = sparseEdges[i][1], w = sparseEdges[i][2];
        sparseAdj[u].push_back(make_pair(v, w));
        sparseAdj[v].push_back(make_pair(u, w));
    }
    for (int i = 0; i < denseEdges.size(); i++)
    {
        int u = denseEdges[i][0], v = denseEdges[i][1], w = denseEdges[i][2];
        denseAdj[u].push_back(make_pair(v, w));
        denseAdj[v].push_back(make_pair(u, w));
    }

    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    // -------- Sparse Graph --------
    QueryPerformanceCounter(&start);
    Prims(V, sparseAdj,true); // <- Use Prims here
    QueryPerformanceCounter(&end);
    cout << "Prims          | Sparse    | 50    | 125   | ";
    PerformanceMeasure(start, end, freq);
    cout << endl;

    QueryPerformanceCounter(&start);
    Kruskal(V, sparseEdges);
    QueryPerformanceCounter(&end);
    cout << "Kruskal        | Sparse    | 50    | 125   | ";
    PerformanceMeasure(start, end, freq);
    cout << endl;

    // -------- Dense Graph --------
    QueryPerformanceCounter(&start);
    Prims(V, denseAdj,false); // <- Use Prims here
    QueryPerformanceCounter(&end);
    cout << "Prims          | Dense     | 50    | 1225  | ";
    PerformanceMeasure(start, end, freq);
    cout << endl;

    QueryPerformanceCounter(&start);
    Kruskal(V, denseEdges);
    QueryPerformanceCounter(&end);
    cout << "Kruskal        | Dense     | 50    | 1225  | ";
    PerformanceMeasure(start, end, freq);
    cout << endl;

    return 0;
}
