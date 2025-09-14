#include <windows.h>
#include <psapi.h>
#include <bits/stdc++.h>
#pragma comment(lib, "Psapi.lib") // Needed for MSVC linking

#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62

const int INF = 1e9;
const int MIN_WEIGHT = 1;  // non-negative weights
const int MAX_WEIGHT = 20; // maximum weight

using namespace std;

// ----------------- Bellman-Ford -----------------
void BellmanFord(vector<vector<int>> adj, int V, int E, vector<int> &distance, bool &flag)
{
    distance[V - 1] = 0; // new source
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = adj[j][0];
            int v = adj[j][1];
            int w = adj[j][2];
            if (distance[u] != INF && distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
            }
        }
    }
    flag = false;
    for (int j = 0; j < E; j++)
    {
        int u = adj[j][0];
        int v = adj[j][1];
        int w = adj[j][2];
        if (distance[u] != INF && distance[v] > distance[u] + w)
        {
            flag = true;
        }
    }
}

// ----------------- Dijkstra -----------------
void Dijkstra(vector<pair<int,int>> adj[], int V, int src, vector<int>& distance) {
    distance.assign(V, INF);
    distance[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int node = pq.top().second;
        int distNode = pq.top().first;
        pq.pop();

        if (distNode > distance[node]) continue; // skip outdated entry

        for (auto &edge : adj[node]) {
            int neighbour = edge.first;
            int weight = edge.second;
            if (distance[neighbour] > distance[node] + weight) {
                distance[neighbour] = distance[node] + weight;
                pq.push({distance[neighbour], neighbour});
            }
        }
    }
}

// ----------------- Johnson -----------------
void Johnson(int V, int E, vector<vector<int>> &edges)
{
    for (int i = 0; i < V; i++)
    {
        edges.push_back({V, i, 0}); // add extra vertex for Bellman-Ford
    }

    vector<int> h(V + 1, INF);
    bool flag;
    BellmanFord(edges, V + 1, E + V, h, flag);

    if (flag)
    {
        cout << "Graph has a negative cycle!\n";
        return;
    }

    vector<pair<int, int>> adj[V];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (u == V)
            continue;
        int w_new = w + h[u] - h[v];
        adj[u].push_back(make_pair(v, w_new));
    }

    vector<vector<int>> distAll(V, vector<int>(V, INF));
    for (int u = 0; u < V; u++)
    {
        vector<int> dist;
        Dijkstra(adj, V, u, dist);
        for (int v = 0; v < V; v++)
        {
            if (dist[v] < INF)
            {
                distAll[u][v] = dist[v] + h[v] - h[u];
            }
        }
    }
}

void FloydWarshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Replace -1 with INT_MAX to represent infinity
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Replace INT_MAX back to -1 to indicate no path
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INT_MAX)
                matrix[i][j] = -1;
        }
    }
}

// ----------------- Graph Generators -----------------
void generateSparseGraph(int V, int E, vector<vector<int>> &edges)
{
    edges.clear();
    set<pair<int, int>> used;
    srand(time(0));
    while ((int)edges.size() < E)
    {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v)
            continue;
        if (used.count(make_pair(u, v)))
            continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        edges.push_back({u, v, w});
        used.insert(make_pair(u, v));
    }
}

void generateDenseGraph(int V, vector<vector<int>> &edges)
{
    edges.clear();
    set<pair<int, int>> used;
    srand(time(0));
    while ((int)edges.size() < 1250)
    {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v)
            continue;
        if (used.count(make_pair(u, v)))
            continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        edges.push_back({u, v, w});
        used.insert(make_pair(u, v));
    }
}

void generateSparseMatrix(int V, int E, vector<vector<int>> &matrix)
{
    matrix.assign(V, vector<int>(V, -1)); // -1 = no edge
    for (int i = 0; i < V; i++)
        matrix[i][i] = 0;

    set<pair<int, int>> used;
    srand(time(0));
    while ((int)used.size() < E)
    {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v)
            continue; // no self-loop
        if (used.count({u, v}))
            continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        matrix[u][v] = w;
        used.insert({u, v});
    }
}

void generateDenseMatrix(int V, vector<vector<int>> &matrix)
{
    matrix.assign(V, vector<int>(V, -1));
    for (int i = 0; i < V; i++)
        matrix[i][i] = 0;

    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (u == v)
                continue;
            int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
            matrix[u][v] = w;
        }
    }
}

// ----------------- Performance Measurement -----------------
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
        cout <<""<<elapsed <<"           | "<< energy<<"    |  " << peakMemUsed<<"      |  " << co2;
        // printf("Execution time: %.6f seconds\n", elapsed);
        //   printf("Estimated energy consumption: %.2f Joules\n", energy);
        //  printf("Peak Memory Usage: %zu KB\n", peakMemUsed / 1024);
        //  printf("Estimated CO2 emissions (Bangladesh): %.8f kg\n", co2);
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
    cout << "Algorithm" << "      | " << "Graph Type" << "| " << "Nodes" << " | " << "Edges" << " | " << "Execution Time(s)" << "   | " << "Energy(J)" << "   | " << "Peak Memory(KB)" << " | " << "CO2 Emissions (kg,BD)" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    int V = 500;
    int sparseE = 125;
    vector<vector<int>> sparseEdges, denseEdges;
    vector<vector<int>> sparseMatrix, denseMatrix;

    generateSparseGraph(V, sparseE, sparseEdges);
    generateDenseGraph(V, denseEdges);

    generateSparseMatrix(V, sparseE, sparseMatrix);
    generateDenseMatrix(V, denseMatrix);

    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);

        // -------- Sparse Graph --------
    QueryPerformanceCounter(&start);
    Johnson(V, sparseEdges.size(), sparseEdges);
    QueryPerformanceCounter(&end);
    cout << "Johnson        | Sparse    | 50    | 125   | ";
    PerformanceMeasure(start, end, freq);
    cout<<endl;
    QueryPerformanceCounter(&start);
    FloydWarshall(sparseMatrix);
    QueryPerformanceCounter(&end);
    cout << "Floyd-Warshall | Sparse    | 50    | 125   | ";
    PerformanceMeasure(start, end, freq);
    cout<<endl;
    // -------- Dense Graph --------
    QueryPerformanceCounter(&start);
    Johnson(V, denseEdges.size(), denseEdges);
    QueryPerformanceCounter(&end);
    cout << "Johnson        | Dense     | 50    | 1225  | ";
    PerformanceMeasure(start, end, freq);
    cout<<endl;
    QueryPerformanceCounter(&start);
    FloydWarshall(denseMatrix);
    QueryPerformanceCounter(&end);
    cout << "Floyd-Warshall | Dense     | 50    | 1225  | ";
    PerformanceMeasure(start, end, freq);

    return 0;
}
