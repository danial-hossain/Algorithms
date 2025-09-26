#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS from given source s
void bfs(vector<vector<int>>& adj, int s) 
{
    // Create a queue for BFS
    queue<int> q;  

    // Initially mark all the vertices as not visited
    vector<bool> visited(adj.size(), false);

    // Mark the source node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int curr = q.front();
        q.pop();
        cout << curr + 1 << " ";  // Output the visited node (convert back to 1-indexed)

        // Get all adjacent vertices of the dequeued vertex curr
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

// Add edge to the undirected graph
void addEdge(vector<vector<int>>& adj, int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

int main() 
{
    int n, m, x;
    cin >> n >> m; // Number of nodes (n) and edges (m)

    vector<vector<int>> adj(n); // Adjacency list for the graph

    // Add edges to the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Adjust for 1-indexed input by subtracting 1
        addEdge(adj, u - 1, v - 1);  // Convert to 0-based indexing
    }

    cout << "BFS starting from: \n";
    cin >> x;

    // Ensure the starting node x is within valid range
    if (x < 1 || x > n) {
        cout << "Invalid starting node!" << endl;
        return 1;  // Exit the program with an error
    }

    // Perform BFS starting from node x (adjust for 0-based indexing)
    bfs(adj, x - 1);  // Convert to 0-based indexing

    return 0;
}
