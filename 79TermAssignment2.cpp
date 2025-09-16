#include <windows.h>
#include <psapi.h>
#include <bits/stdc++.h>
#pragma comment(lib, "Psapi.lib")

#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62

const int INF = 1e9;
const int MIN_WEIGHT = 1;
const int MAX_WEIGHT = 20;

using namespace std;

// ---------------- Prim's Algorithm ----------------
// PQ-based for sparse graphs, Array-based for dense graphs
int PrimsOptimized(int V, vector<vector<pair<int,int>>> &adj, bool dense = false) {
    if(!dense) {
        // Sparse: optimized PQ-based
        vector<int> key(V, INF);
        vector<bool> inMST(V,false);
        key[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int cost = 0;

        while(!pq.empty()) {
            auto [wt,u] = pq.top(); pq.pop();
            if(inMST[u]) continue;
            inMST[u] = true;
            cost += wt;

            for(auto &edge : adj[u]) {
                int v = edge.first, w = edge.second;
                if(!inMST[v] && w < key[v]) {
                    key[v] = w;
                    pq.push({w,v});
                }
            }
        }
        return cost;
    } else {
        // Dense: Array-based
        vector<int> key(V, INF);
        vector<bool> inMST(V,false);
        key[0] = 0;
        int cost = 0;

        for(int count = 0; count < V; ++count) {
            int u = -1;
            for(int i = 0; i < V; ++i)
                if(!inMST[i] && (u==-1 || key[i]<key[u])) u = i;
            inMST[u] = true;
            cost += key[u];

            for(auto &edge : adj[u]) {
                int v = edge.first, w = edge.second;
                if(!inMST[v] && w < key[v]) key[v] = w;
            }
        }
        return cost;
    }
}

// ---------------- Kruskal's Algorithm ----------------
int FindParent(int u, vector<int> &parent) {
    if(u == parent[u]) return u;
    return parent[u] = FindParent(parent[u], parent);
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank) {
    int pu = FindParent(u,parent);
    int pv = FindParent(v,parent);
    if(rank[pu] < rank[pv]) parent[pu] = pv;
    else if(rank[pu] > rank[pv]) parent[pv] = pu;
    else { parent[pv]=pu; rank[pu]++; }
}

int Kruskal(int V, vector<vector<int>> &edges) {
    vector<int> parent(V), rank(V,0);
    for(int i=0;i<V;i++) parent[i]=i;

    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){ return a[2]<b[2]; });

    int cost=0, edgesCount=0;
    for(auto &e : edges){
        int u=e[0], v=e[1], w=e[2];
        if(FindParent(u,parent)!=FindParent(v,parent)){
            cost+=w;
            UnionByRank(u,v,parent,rank);
            edgesCount++;
        }
        if(edgesCount==V-1) break;
    }
    return cost;
}

// ---------------- Graph Generators ----------------
void generateSparseGraph(int V, int E, vector<vector<int>> &edges) {
    edges.clear();
    set<pair<int,int>> used;
    srand(time(0));
    while((int)edges.size()<E){
        int u=rand()%V, v=rand()%V;
        if(u==v || used.count({u,v}) || used.count({v,u})) continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT-MIN_WEIGHT+1);
        edges.push_back({u,v,w});
        used.insert({u,v});
    }
}

void generateDenseGraph(int V, vector<vector<int>> &edges) {
    edges.clear();
    set<pair<int,int>> used;
    srand(time(0));
    int totalEdges = V*(V-1)/2;
    while((int)edges.size()<totalEdges){
        int u=rand()%V, v=rand()%V;
        if(u==v || used.count({u,v}) || used.count({v,u})) continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT-MIN_WEIGHT+1);
        edges.push_back({u,v,w});
        used.insert({u,v});
    }
}

// ---------------- Performance Measurement ----------------
void PerformanceMeasure(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq) {
    double elapsed = (double)(end.QuadPart-start.QuadPart)/freq.QuadPart;
    double energy = CPU_POWER_WATTS * elapsed;
    double energy_kWh = energy/3.6e6;
    double co2 = energy_kWh*BD_EMISSION_FACTOR;

    PROCESS_MEMORY_COUNTERS_EX pmc;
    if(GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        SIZE_T peakMemUsed = pmc.PeakWorkingSetSize;
        cout << elapsed <<"           | "<< energy<<"    | "<< peakMemUsed<<"      | "<< co2;
    } else {
        printf("Failed to get memory info.\n");
    }
}

// ----------------- Main -----------------
int main(){
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Algorithm      | Graph Type| Nodes | Edges | Execution Time(s)   | Energy(J)   | Peak Memory(KB) | CO2 Emissions (kg,BD)" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    int V=50, sparseE=125;
    vector<vector<int>> sparseEdges, denseEdges;
    generateSparseGraph(V,sparseE,sparseEdges);
    generateDenseGraph(V,denseEdges);

    // Build adjacency lists
    vector<vector<pair<int,int>>> sparseAdj(V), denseAdj(V);
    for(auto &e: sparseEdges){
        sparseAdj[e[0]].push_back({e[1], e[2]});
        sparseAdj[e[1]].push_back({e[0], e[2]});
    }
    for(auto &e: denseEdges){
        denseAdj[e[0]].push_back({e[1], e[2]});
        denseAdj[e[1]].push_back({e[0], e[2]});
    }

    LARGE_INTEGER freq,start,end;
    QueryPerformanceFrequency(&freq);

    // -------- Sparse Graph --------
    QueryPerformanceCounter(&start);
    PrimsOptimized(V, sparseAdj, false);
    QueryPerformanceCounter(&end);
    cout << "PrimsOptimized | Sparse    | 50    | 125   | ";
    PerformanceMeasure(start,end,freq); cout<<endl;

    QueryPerformanceCounter(&start);
    Kruskal(V,sparseEdges);
    QueryPerformanceCounter(&end);
    cout << "Kruskal        | Sparse    | 50    | 125   | ";
    PerformanceMeasure(start,end,freq); cout<<endl;

    // -------- Dense Graph --------
    QueryPerformanceCounter(&start);
    PrimsOptimized(V, denseAdj, true);
    QueryPerformanceCounter(&end);
    cout << "Prims           | Dense     | 50    | 1225  | ";
    PerformanceMeasure(start,end,freq); cout<<endl;

    QueryPerformanceCounter(&start);
    Kruskal(V,denseEdges);
    QueryPerformanceCounter(&end);
    cout << "Kruskal        | Dense     | 50    | 1225  | ";
    PerformanceMeasure(start,end,freq); cout<<endl;

    return 0;
}
