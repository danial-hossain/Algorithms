#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>adj[],int V,vector<int>&visited,vector<int>&parent,vector<int>&ans,int src,int paren)
{
   visited[src]=1;
   ans.push_back(src);
   for(int i=0;i<adj[src].size();i++)
   {
    if(!visited[adj[src][i]])
    {
        parent[adj[src][i]]=src;
        DFS(adj,V,visited,parent,ans,adj[src][i],src);
    }
   }
}
int main()
{
    int V , E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>> u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(V,0);
    vector<int>parent(V,-1);
    vector<int>ans;
    DFS(adj,V,visited,parent,ans,0,-1);
    int des;
    cout<<"Enter Destination : ";
    cin>>des;
    vector<int>path;
    while(parent[des]!=-1)
    {
        path.push_back(des);
        des=parent[des];
    }
    path.push_back(0);
    reverse(path.begin(),path.end());
    for(auto i:path)
    {
        cout<<i <<" ";
    }
}