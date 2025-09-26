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

int Prims(int V, vector<vector<pair<int,int>>> &adj,bool sparse)
{
    // Min-heap: {weight, {node, parent}}
    //amra heap e -> {weight,node,parent} ei structure e element gula push korbo
    priority_queue<pair<int, pair<int,int>>,
                   vector<pair<int, pair<int,int>>>,
                   greater<pair<int, pair<int,int>>>> pq;

    vector<int> key(V, INT_MAX);   // stores best edge weight for each node

    vector<int> parent(V, -1);     // parent of each node in MST
    //surute sobar parent -1 -> source parent -1
    vector<bool> inMST(V, false);  // whether node is included in MST
    //node include hole isMST one Hobe
    //pottekta  element heap theke ber korar por check korbo seta isMST te ase kina
    //isMST te na thakle  setake ->isMST[node]=1 korbo
    //erpor setar parent update korbo ->parent er kaz spanning tree ta draw kora

    int cost = 0;

    // Start from node 0
    key[0] = 0; //Source Node
    pq.push({0, {0, -1}});   // {weight, {node, parent}}
    // source ke amra heap e push krlam
    //erpor oitare pop korbo while looper vitor,pop holo mark korlam inMST[node] =1,then oitar jonno weight parent update,then oitar sather gulare dibo heaper vitore

    while (!pq.empty())
    {
        int wt   = pq.top().first;
        int node = pq.top().second.first;
        int par  = pq.top().second.second;
        pq.pop();

        if (inMST[node]) continue;  // skip duplicates
        //Jeda isMST te ase,oitar sather edge gulare ar nibona heap e

        // Include node in MST
        inMST[node] = true;
        cost += wt;
        parent[node] = par;

        // Check all adjacent edges
        //adj[node] is a vector of pairs → vector<pair<int,int>>
        //Each edge inside it is a pair<int,int> (something like {neighbor, weight}).
        //auto lets the compiler deduce the type automatically
        //edge becomes a reference to a pair<int,int>.without auto --> we had to write -->  for (pair<int,int> &edge : adj[node])
        //We used the foreach loop,without it
        // for (int i = 0; i < adj[node].size(); i++) {
        //pair<int,int> edge = adj[node][i];


        for (auto &edge : adj[node])
        {
            //jake amra heap e push krci take to pop krlam
            //jare push krcilam tar sathe je node gula cilo segulore amra isMST te ase kina check krbo
            //na thake taderke amra push korbo heap e
            //eta krteci karon edire add korle cycle create hobe
            int adjNode = edge.first; //adjNode -> neighbout node
            int edgeWt  = edge.second; //node - adjNode er modder je weight

            // Only push if it's a better edge
            if (!inMST[adjNode] && edgeWt < key[adjNode])
            {
                key[adjNode] = edgeWt;
                //key hoitece amra jodi kono akta node re connect kori sei connect korte best minimal edge konta setare store krbe
                //pottekta vertex er jonno update krbo jodi minimum weight er edge pai
                //eta krteci ensure korte Time Complexity ElogV thake
                //Eta na korle ager concept ,sob gula Edge re amra heap e push krteci tokon Kruskal better hoye jacce
                //Each vertex only updates when we find a better edge
                pq.push({edgeWt, {adjNode, node}});
                //Weight=edgeWt
                //Node=adjNode
                //Parent=node
            }
        }
    }

    // Now parent[] contains MST structure, cost is total weight
    return cost;
}


int Prims2(int V, vector<vector<pair<int,int>>> &adj,bool sparse)
{
    if(sparse)

    {

        // Min-heap: {weight, {node, parent}}
        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<pair<int, pair<int,int>>>> pq;

        vector<int> key(V, INT_MAX);   // stores best edge weight for each node
        vector<int> parent(V, -1);     // parent of each node in MST
        vector<bool> inMST(V, false);  // whether node is included in MST

        int cost = 0;

        // Start from node 0
        key[0] = 0;
        pq.push({0, {0, -1}});   // {weight, {node, parent}}

        while (!pq.empty())
        {
            int wt   = pq.top().first;
            int node = pq.top().second.first;
            int par  = pq.top().second.second;
            pq.pop();

            if (inMST[node]) continue;  // skip duplicates

            // Include node in MST
            inMST[node] = true;
            cost += wt;
            parent[node] = par;

            // Check all adjacent edges
            for (auto &edge : adj[node])
            {
                int adjNode = edge.first;
                int edgeWt  = edge.second;

                // Only push if it's a better edge
                if (!inMST[adjNode] && edgeWt < key[adjNode])
                {
                    key[adjNode] = edgeWt;
                    pq.push({edgeWt, {adjNode, node}});
                }
            }
        }

        // Now parent[] contains MST structure, cost is total weight
        return cost;


    }

    else
    {
        //this is adjancy matrix + linear search based ,No heap,Better for Dense graph,T(n)=O(V^2)
        vector<int> key(V, INF);
        //Start all as INF (infinity).Matrix a Usually Amra Ja kori
        vector<bool> inMST(V, false);
        key[0] = 0;
        //key[i] = the minimum edge weight needed to connect vertex i to the MST.
        int cost = 0;

        for(int i=0; i<V; i++)
        {
            //Run V iterations (since MST has V vertices).
            //each time, pick the vertex u not yet in MST with the smallest key[j]
            //This is done with a linear scan of all vertices.Complexity: O(V²) because of this scan.

            int u=-1;
            //Surute amra je parent -1 dhori seta check korte
            //inMST --> MST te ase kina check krci
            //best connecting minimum edge ta amra rakhlam key te
            //u=j ; Marking The best candidate like the minimal edge connecting the node
            for(int j=0; j<V; j++)
            {
                if(!inMST[j] && (u==-1 || key[j]<key[u])) u=j;
            }
            inMST[u] = true;
            cost += key[u];
            //Below this This part is updating the keys of vertices adjacent to u in Prim’s algorithm. Let’s go line by line:
            for(int j = 0; j < adj[u].size(); j++)
                //amra j re to ber korlam oi node e jabo ,cuz setate minimal edge,then setar iterate over all neighbors of u
            {
                int v = adj[u][j].first; //neighbour node
                int w = adj[u][j].second; //node j - v connecting edge weight
                if(!inMST[v] && w < key[v])
                {
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
    //Amra kono element er ultimate Parent ber korbo,Parent jodi same hoy tahole tara same set

    return parent[u] = FindParent(parent[u], parent);
    //parent[u]--> amra kono akta element er je ultimate parent pelam setake amra sathe sathe update kore dilam-> path compression
    //path compression na krle pottek element er ultimate parent khujte gele time complexity bere jeto
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    //rank jodi keo karo cheye boro hoy thaole kintu barbena
    //rank use => after finding they are different set,kake kar sathe merge korbo setar jonno amra rank use kri
    //merge amra akta arektar sathe kortei pari but lower rank er sathe higer rank will result increadin time complexity

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
        //duijoner rank same -> akon barbe like 0 - 1, 2 -4 ,erokom same rank
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


         // Check all adjacent edges
        //adj[node] is a vector of pairs → vector<pair<int,int>>
        //Each edge inside it is a pair<int,int> (something like {neighbor, weight}).
        //auto lets the compiler deduce the type automatically
        //edge becomes a reference to a pair<int,int>.without auto --> we had to write -->  for (pair<int,int> &edge : adj[node])
        //We used the foreach loop,without it
        // for (int i = 0; i < adj[node].size(); i++) {
        //pair<int,int> edge = adj[node][i];

    for (auto &e : edges)
    {
        pq.push({e[2], {e[0], e[1]}});
        //pq te push krteci {weight,u,v dui node ei order e},khatay dya 1,2 erpor 3,4 ejonno
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
            //duitar ultimate parent same ->same set,add korbona
            //alada ultimate parent->alada set -> add korbo
            cost += wt;
            UnionByRank(u, v, parent, rank);// jokon deklam era alada set,tokon eder rank er basis e eder add korbo
            edgeCount++;
            //kruskal algorithm e amra always v-1 porjonto edge e nibo
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
    //edge vector e age kicu thakle oita clear kore nilam ;optional use case
    set<pair<int, int>> used; //// Track edges to avoid duplicates

    srand(time(0));
    //Normally, rand() always produces the same sequence of numbers each time the program runs,
    // because it starts from a fixed seed (by default, seed = 1).
    //srand(time(0)) does not guarantee that numbers will be unique.
    //It only makes the sequence less predictable across program runs
    //srand(time(0)) makes random numbers less predictable (different each run).


    while ((int)edges.size() < E)
        //edge.clear() kore to pura edge ta faka korlam,
        //johon oi edlist list amr given edge number er soman na hocce totokkhon loop cholbe
    {

        int u = rand() % V;
         //%V --> V er value 0-50,so u er value jeno 0-50 er modde thake
        int v = rand() % V;
           //same
        if (u == v || used.count(make_pair(u, v)) || used.count(make_pair(v, u)))  // No self-loops
            continue;

         // if (u == v) continue;       // No self-loops
        //u =v ,self loop banabe
       // Self-loops don�t affect shortest paths, since distance from a node to itself is always 0.
       //shortest path algorithm e self looper kono affect nai,jehutu nijer theke nijer distance 0,
       //incase eitay negative weight bosatale,will occur negative weight cycle


         // if (used.count(make_pair(u, v))) continue; // Skip duplicate
        //u,v ki set e age theke cilo,thakle skip
        //for sparce graph we need to avoid rewriting issue
        //jeta amader sob node connect holona,rewriting total edge dilam 125 seta theke kom edge dibe
        //jehutu edge er value rewrite hoye jacce




        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1); //randomly generated wright
        vector<int> e;
        e.push_back(u);
        e.push_back(v);
        e.push_back(w);
        edges.push_back(e); // edged hoilo vector er vector,so element gula vector form ei edge er vitor push disi vector<vector>->nibe vector
        used.insert(make_pair(u, v));
           //set list er vitore push kore dilam,jate seta future e paile ar na nei ,avoid rewriting
    }
}

void generateDenseGraph(int V, vector<vector<int>> &edges)
{
    edges.clear();
    //edge.clear() kore to pura edge ta faka korlam
    //johon oi edlist list amr given edge number er soman na hocce totokkhon loop cholbe

    set<pair<int,int>> used;
    srand(time(0));

    int totalEdges = V * (V-1) / 2; // V*(V-1)/2 for 50 nodes calculate korlam ,totalEdge->1225 now
      //dense graph,loop cholbe given Edge number er soman,are conditon thakbe edge list e totogula edge add holo kina

    while ((int)edges.size() < totalEdges)
    {
        int u = rand() % V;
          //%V --> V er value 0-50,so u er value jeno 0-50 er modde thake
        int  v = rand() % V;

        if(u == v || used.count({u,v}) || used.count({v,u})) continue;



         // if (u == v) continue;       // No self-loops
        //u =v ,self loop banabe
       // Self-loops don�t affect shortest paths, since distance from a node to itself is always 0.
       //shortest path algorithm e self looper kono affect nai,jehutu nijer theke nijer distance 0,
       //incase eitay negative weight bosatale,will occur negative weight cycle


         // if (used.count(make_pair(u, v))) continue; // Skip duplicate
        //u,v ki set e age theke cilo,thakle skip
        //for sparce graph we need to avoid rewriting issue
        //jeta amader sob node connect holona,rewriting total edge dilam 125 seta theke kom edge dibe
        //jehutu edge er value rewrite hoye jacce



        int w = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1); //randomly generated weight
        edges.push_back({u, v, w});
        //edge list e u,v,w input dilam
        used.insert({u,v});
        //set list er vitore push kore dilam
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
   // Build edgelist lists
    vector<vector<int>> sparseEdges, denseEdges;
    //vector er vector declare
    generateSparseGraph(V, sparseE, sparseEdges);
    //sparese grapher kintu edge ase,its edge<complete graph edge
    generateDenseGraph(V, denseEdges);


    vector<vector<pair<int, int>>> sparseAdj(V), denseAdj(V);
    //This declares adjacency lists for two graphs: sparseAdj and denseAdj
    // adjacency list banailm for the prims algorithm use

    for (int i = 0; i < sparseEdges.size(); i++)
    {
        //sparseEdge hoitece edge list,oita theke banano adjacecny list
        int u = sparseEdges[i][0];
        int  v = sparseEdges[i][1];
        int  w = sparseEdges[i][2];
        sparseAdj[u].push_back(make_pair(v, w));
        sparseAdj[v].push_back(make_pair(u, w));
    }
    for (int i = 0; i < denseEdges.size(); i++)
    {
        int u = denseEdges[i][0];
        int v = denseEdges[i][1];
        int  w = denseEdges[i][2];
        denseAdj[u].push_back(make_pair(v, w));
        denseAdj[v].push_back(make_pair(u, w));
        //adjacency list look
        // 0 -> (1,2) (2,4)
        // 1 -> (3,5) (5,6)
        //edge list look
        //(1,2),(3,5) etc
    }

    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    // -------- Sparse Graph --------
    QueryPerformanceCounter(&start);
    Prims(V, sparseAdj,true); // <- Use Prims here
    //true er apadoto code e kaz nai,keo jodi prim2 {adjoint matrix +linear search use kore setar jonno }

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
