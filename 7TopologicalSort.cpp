#include<bits/stdc++.h>
using namespace std;

void Topological(vector<int>adj[],int V,int src,vector<bool>&visited,stack<int>&ans)
{
    visited[src]=1;
    for(int i=0;i<adj[src].size();i++)
    {
        if(!visited[adj[src][i]])
        {
   
         Topological(adj,V,adj[src][i],visited,ans);
        }
    }
    ans.push(src);
}
int main()
{
    int V,E;
    cin>> V >> E;
    vector<int>adj[V];
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin >>u >>v;
        adj[u].push_back(v);
    }
    stack<int>ans;
    vector<bool>visited(V,0);
    vector<int>sort;
   
    Topological(adj,V,0,visited,ans);
    while(!ans.empty())
    {
       sort.push_back(ans.top());
       ans.pop();
    }
     for(auto i: sort)
     {
        cout<<i;
     }

}