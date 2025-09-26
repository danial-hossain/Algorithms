#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<pair<int, int>> adj[], stack<int> &s,
vector<bool> &visited)
{
visited[node] = 1;
for (int j = 0; j < adj[node].size(); j++)
{
if (!visited[adj[node][j].first])
{
DFS(adj[node][j].first, adj, s, visited);
}
}
s.push(node);
}

vector<int> shortestPath(int N, int M, vector<pair<int, int>> adj[],int src)
{
stack<int> s1;
vector<bool> visited(N, 0);
DFS(0, adj, s1, visited);
vector<int> dist(N, INT_MAX);
vector<int> parent(N, 0);
dist[src] = 0;
parent[src] = -1;
while (!s1.empty())
{
int node = s1.top();
s1.pop();
for (int j = 0; j < adj[node].size(); j++)
{
int neighbour = adj[node][j].first;
int weight = adj[node][j].second;
if (dist[node] + weight < dist[neighbour])
{
dist[neighbour] = dist[node] + weight;
parent[neighbour] = node;
}
}
}
for (int i = 0; i < N; i++)
{
if (dist[i] == INT_MAX)
dist[i] = -1;
}
return parent;
}

int main()
{
int N, M;
cout << "Enter number of nodes and edges: ";
cin >> N >> M;
vector<pair<int, int>> adj[N];
for (int i = 0; i < M; i++)
{
int u, v, w;
cin >> u >> v >> w;
adj[u].push_back(make_pair(v, w));
}
int src;
cout<<"Enter the Source : ";
cin>>src;
vector<int> result = shortestPath(N, M, adj,src);
cout << "Enter the Destination Node : ";
int destination;
cin >> destination;
cout << "Shortest Path from node "<<src<<" to node " << destination <<
" :" << endl;
vector<int> path;
while (destination != -1)
{
path.push_back(destination);
destination = result[destination];
}
reverse(path.begin(), path.end());
for (int node : path)
{
cout << node << " ";
}
return 0;
}