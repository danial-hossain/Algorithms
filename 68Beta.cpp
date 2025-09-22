#include <windows.h>       // Windows API for performance and memory measurement
#include <psapi.h>         // Process Status API, to get memory usage
#include <bits/stdc++.h>   // Includes all standard C++ headers
#pragma comment(lib, "Psapi.lib") // Link the Psapi library for memory functions

#define CPU_POWER_WATTS 65.0          // Approximate CPU power consumption in watts
#define BD_EMISSION_FACTOR 0.62       // kg CO2 per kWh in Bangladesh

const int INF = 1e9;                 // Represents "infinity" for unreachable nodes
const int MIN_WEIGHT = 1;            // Minimum edge weight,Uddipok e deya
const int MAX_WEIGHT = 100;          // Maximum edge weight,Uddipok e deya

using namespace std;

// ----------------- Bellman-Ford -----------------
// Computes shortest paths from a source in a graph, detects negative cycles
void BellmanFord(vector<vector<int>> adj, int V, int E, vector<int> &distance, bool &flag)
{
    distance[V - 1] = 0; // Add a virtual source at index V-1,Suppose Total node cilo 0-4,5 ta
    //Akta node add krlam,Total node 6-->0,1,2,3,4,5 ;so 5 is our new node
    for (int i = 0; i < V - 1; i++)  // Relax all edges V-1 times,Bellman Ford,Outer loop V-1 times
    {
        for (int j = 0; j < E; j++) //Iterate For Each Edges in Edge list
        {
            int u = adj[j][0];
            int v = adj[j][1];
            int w = adj[j][2];
            if (distance[u] != INF && distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;  // Relax edge
            }
        }
    }

    flag = false; // Initialize negative cycle flag
    for (int j = 0; j < E; j++) // Check for negative cycles
    {
        int u = adj[j][0];
        int v = adj[j][1];
        int w = adj[j][2];
        if (distance[u] != INF && distance[v] > distance[u] + w)
        {
            flag = true; // Negative cycle detected
            //Minimum Distance Graph Ber korar por arekta  All Edge check dile jodi distance kome-->Negative Cycle Exists
        }
    }
}

// ----------------- Dijkstra -----------------
// Computes single-source shortest path for graphs with non-negative weights
void Dijkstra(vector<pair<int,int>> adj[], int V, int src, vector<int>& distance) {

    distance.assign(V, INF);    // Initialize distances to INF
    //distance.assign-->vector<int>distance(V,INF)
    distance[src] = 0;          // Distance to source is 0

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});          // Push source vertex into priority queue
    //source ke pariority queue te push

    while (!pq.empty()) {
        int node = pq.top().second;

        int distNode = pq.top().first;
        pq.pop();

        if (distNode > distance[node]) continue; // Skip outdated entry
        //Ei condition ta check na krleo hoy cuz distance[node]/Neightbour Distace theke jodi Source noder weight e boro hoye jay jibone update hobena

        //Dijkstra still works correctly because you only update a neighbor if the new path is shorter than the current stored distance

        for (auto &edge : adj[node]) {           // Explore neighbors
                //Sob gula neightbour node check korteci
            int neighbour = edge.first;
            int weight = edge.second;
            if (distance[neighbour] > distance[node] + weight) {
                //shortest distance update
                distance[neighbour] = distance[node] + weight; // Relax edge
        //Amra node select kre update kore dijkstra e ,akbar kono node select hole setake abr update korbona
                pq.push({distance[neighbour], neighbour});
            }
        }
    }
}

// ----------------- Johnson -----------------
// Computes all-pairs shortest paths efficiently for sparse graphs
void Johnson(int V, int E, vector<vector<int>> &edges)
{
    for (int i = 0; i < V; i++)
    {
        edges.push_back({V, i, 0}); // Add extra vertex for Bellman-Ford reweighting
        //je node ta dhore nisilam oita theke sob node je distance 0,akon ei edge listao edge[list] e dukalam
    }

    vector<int> h(V + 1, INF); // Potential array for edge reweighting
    //reweighting --> w'(u,v)=distance[u]+w(u,v)-distance[v]

    bool flag;
    BellmanFord(edges, V + 1, E + V, h, flag); // Run Bellman-Ford

    if (flag) // Negative cycle check
    {
        cout << "Graph has a negative cycle!\n";
        return;
    }

    vector<pair<int, int>> adj[V]; // Adjacency list for reweighted graph
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (u == V) // Skip virtual vertex
            continue;
        int w_new = w + h[u] - h[v]; // Reweight edge to remove negatives
         //reweighting --> w'(u,v)=distance[u]+w(u,v)-distance[v]

        adj[u].push_back(make_pair(v, w_new));
    }

    vector<vector<int>> distAll(V, vector<int>(V, INF)); // Store all-pairs distances
    for (int u = 0; u < V; u++)
    {
        vector<int> dist;
        Dijkstra(adj, V, u, dist); // Run Dijkstra from each vertex
        for (int v = 0; v < V; v++)
        {
            if (dist[v] < INF)
            {
                distAll[u][v] = dist[v] + h[v] - h[u]; // Restore original distances
                //d(u,v)=d'(u,v) + h[v]-h[u] ;ekhane h holo bellman for run kore amra je distacne array ta pelam
                //d holo distance array jeta amra akta source dhore dijkstra theke pabo
            }
        }
    }
}

// ----------------- Floyd-Warshall -----------------
// Computes all-pairs shortest paths for any graph (including negative edges)
void FloydWarshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    //eikhane alada vertex dite hoynai cuz maxtrix.size gives the total number of row of the matrix,oitare vertex e bola jay

    // Replace -1 with INT_MAX to represent infinity
    //FLoyed warshall e amra surute sob edge infinity dhori oita
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }

    // Main triple loop
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

    // Restore -1 for unreachable paths
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
// Sparse edge list
void generateSparseGraph(int V, int E, vector<vector<int>> &edges)
{
    edges.clear();
    //edge vector e age kicu thakle oita clear kore nilam ;optional use case
    set<pair<int, int>> used;   // Track edges to avoid duplicates
    srand(time(0));
    while ((int)edges.size() < E)
    {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v) continue;           // No self-loops
        if (used.count(make_pair(u, v))) continue; // Skip duplicate
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        edges.push_back({u, v, w});
        used.insert(make_pair(u, v));
    }
}

// Dense edge list
void generateDenseGraph(int V, vector<vector<int>> &edges)
{
    edges.clear();
    set<pair<int, int>> used;
    srand(time(0));
    while ((int)edges.size() < 1225) // V*(V-1)/2 for 50 nodes
    {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v) continue;
        if (used.count(make_pair(u, v))) continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        edges.push_back({u, v, w});
        used.insert(make_pair(u, v));
    }
}

// Sparse adjacency matrix
void generateSparseMatrix(int V, int E, vector<vector<int>> &matrix)
{
    matrix.assign(V, vector<int>(V, -1)); // Initialize with -1 (no edge)
    for (int i = 0; i < V; i++)
        matrix[i][i] = 0; // Distance to self is 0

    set<pair<int, int>> used;
    srand(time(0));
    while ((int)used.size() < E)
    {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v) continue;
        if (used.count({u, v})) continue;
        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        matrix[u][v] = w;
        used.insert({u, v});
    }
}

// Dense adjacency matrix
void generateDenseMatrix(int V, vector<vector<int>> &matrix)
{
    matrix.assign(V, vector<int>(V, -1));
    for (int i = 0; i < V; i++)
        matrix[i][i] = 0;

    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (u == v) continue;
            int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
            matrix[u][v] = w;
        }
    }
}

// ----------------- Performance Measurement -----------------
void PerformanceMeasure(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq)
{
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart; // Time in seconds
    double energy = CPU_POWER_WATTS * elapsed;                                 // Energy in Joules
    double energy_kWh = energy / 3.6e6;                                         // Convert to kWh
    double co2 = energy_kWh * BD_EMISSION_FACTOR;                               // CO2 in kg

    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc)))
    {
        SIZE_T peakMemUsed = pmc.PeakWorkingSetSize; // Peak memory in bytes
        cout <<""<<elapsed <<"           | "<< energy<<"    |  " << peakMemUsed<<"      |  " << co2;
    }
    else
    {
        printf("Failed to get memory info.\n");
    }
}

// ----------------- Main -----------------
int main()
{
    // Header for performance table
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Algorithm" << "      | " << "Graph Type" << "| " << "Nodes" << " | " << "Edges" << " | " << "Execution Time(s)" << "   | " << "Energy(J)" << "   | " << "Peak Memory(KB)" << " | " << "CO2 Emissions (kg,BD)" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    int V = 50;                 // Number of vertices
    int sparseE = 125;          // Number of edges in sparse graph
    vector<vector<int>> sparseEdges, denseEdges;  // Edge lists
    vector<vector<int>> sparseMatrix, denseMatrix; // Adjacency matrices

    generateSparseGraph(V, sparseE, sparseEdges);  // Sparse edge list
    generateDenseGraph(V, denseEdges);            // Dense edge list

    generateSparseMatrix(V, sparseE, sparseMatrix); // Sparse matrix
    generateDenseMatrix(V, denseMatrix);           // Dense matrix

    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq); // Timer frequency

    // -------- Sparse Graph --------
    QueryPerformanceCounter(&start);
    Johnson(V, sparseEdges.size(), sparseEdges); // Johnson on sparse
    QueryPerformanceCounter(&end);
    cout << "Johnson        | Sparse    | 50    | 125   | ";
    PerformanceMeasure(start, end, freq);
    cout<<endl;

    QueryPerformanceCounter(&start);
    FloydWarshall(sparseMatrix); // Floyd-Warshall on sparse
    QueryPerformanceCounter(&end);
    cout << "Floyd-Warshall | Sparse    | 50    | 125   | ";
    PerformanceMeasure(start, end, freq);
    cout<<endl;

    // -------- Dense Graph --------
    QueryPerformanceCounter(&start);
    Johnson(V, denseEdges.size(), denseEdges); // Johnson on dense
    QueryPerformanceCounter(&end);
    cout << "Johnson        | Dense     | 50    | 1225  | ";
    PerformanceMeasure(start, end, freq);
    cout<<endl;

    QueryPerformanceCounter(&start);
    FloydWarshall(denseMatrix); // Floyd-Warshall on dense
    QueryPerformanceCounter(&end);
    cout << "Floyd-Warshall | Dense     | 50    | 1225  | ";
    PerformanceMeasure(start, end, freq);

    return 0;
}

