#include<bits/stdc++.h>
using namespace std;
void DijkStraTotalSP(vector<pair<int,double>>adj[],int V,vector<int>&visited,vector<double>&distance,vector<int>&path)
{
    int count=V;

    distance[0]=1;
    path[0]=1;
    while(count>0)
    {
        int node=-1;
        double dis=0;
        for(int i=0;i<V;i++)
        {
            if(dis<distance[i] && !visited[i])
            {
                dis=distance[i];
                node=i;
            }
        }
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {
            double weight=adj[node][i].second;
            if(distance[adj[node][i].first]<distance[node]*weight)
            {
                  distance[adj[node][i].first]=distance[node] *weight;
                  path[adj[node][i].first]=path[node];
            }
         
        }
        count--;
    }
}
int main()
{
    int V,E;
    cin>>V >>E;
    vector<pair<int,double>>adj[V];
    for(int i =0;i<E;i++)
    {
        int u,v;
        double w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    vector<double>distance(V,0.0);
    vector<int>visited(V,0);
    vector<int>path(V,0);
    DijkStraTotalSP(adj,V,visited,distance,path);
    for(auto i: distance)
    {
        cout<<i<< " ";
    }
    cout<<endl;
    for(auto i: path)
    {
        cout<<i<< " ";
    }
}