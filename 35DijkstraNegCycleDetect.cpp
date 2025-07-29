#include<bits/stdc++.h>
using namespace std;
bool DijkStraTotalSP(vector<pair<int,int>>adj[],int V,vector<int>&visited,vector<int>&distance,vector<int>&path)
{
    int count=V;
   bool flag=false;
    distance[0]=0;
    path[0]=1;
    while(count>0)
    {
        int node=-1;
        int dis=INT_MAX;
        for(int i=0;i<V;i++)
        {
            if(dis>distance[i] && !visited[i])
            {
                dis=distance[i];
                node=i;
            }
        }
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {
            int weight=adj[node][i].second;
            if(distance[adj[node][i].first]>distance[node] +weight)
            {
                  distance[adj[node][i].first]=distance[node] +weight;
                  path[adj[node][i].first]=path[node];
            }
        
        }
        count--;
    }
 
    {
        int node=-1;
        int dis=INT_MAX;
        for(int i=0;i<V;i++)
        {
            if(dis>distance[i] && !visited[i])
            {
                dis=distance[i];
                node=i;
            }
        }
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {
            int weight=adj[node][i].second;
            if(distance[adj[node][i].first]>distance[node] +weight)
            {
                  distance[adj[node][i].first]=distance[node] +weight;
                  flag=true;
                  path[adj[node][i].first]=path[node];
            }
        
        }
        count--;
    }
    return flag;

}
int main()
{
    int V,E;
    cin>>V >>E;
    vector<pair<int,int>>adj[V];
    for(int i =0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    vector<int>distance(V,INT_MAX);
    vector<int>visited(V,0);
    vector<int>path(V,0);
   bool flag= DijkStraTotalSP(adj,V,visited,distance,path);
    for(auto i: distance)
    {
        cout<<i<< " ";
    }
    cout<<endl;
    for(auto i: path)
    {
        cout<<i<< " ";
    }
    if(flag)
    {
        cout<<"Negative Cycle Detected ";
    }
    else
    {
        cout<<"No Neg Cycle ";
    }
}