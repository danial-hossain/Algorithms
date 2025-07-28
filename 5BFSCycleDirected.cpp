#include<bits/stdc++.h>
using namespace std;
bool BFSCycleDirected(vector<int>adj[],int V,vector<int>&inDeg,vector<int>&ans)
{
    queue<int>q;
      for(int i=0;i<V;i++)
      {
        if(inDeg[i]==0)
        {
           q.push(i);
           ans.push_back(i);
     
        }
      }
      while(!q.empty())
      {
        int node=q.front();
        q.pop();
        for(int i=0;i<adj[node].size();i++)
        {
            inDeg[adj[node][i]]--;
            if(inDeg[adj[node][i]]==0)
            {
               q.push(adj[node][i]);
               ans.push_back(adj[node][i]);
            }
        }
      }
      if(ans.size()==V)
      {
        return false;
      }
      else
      {
        return true;
      }
}

int main()
{
    int V,E;
    cin>> V >>E ;
    vector<int>adj[V];
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>inDeg(V,0);
     vector<int>ans;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
           inDeg[adj[i][j]]++;
        }
    }
    bool flag= BFSCycleDirected(adj,V,inDeg,ans);
    cout<<flag;
}