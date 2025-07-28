#include<bits/stdc++.h>
using namespace std;

void Dijksra(vector<pair<int,int>>adj[],int V,vector<int>&distance,vector<int>&visited,vector<int>&parent)
{
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

       distance[0]=0;
       q.push(make_pair(distance[0],0));
    while(!q.empty())
    {
        int node=q.top().second;


        q.pop();
         visited[node]=1;
        for(int j=0;j<adj[node].size();j++)
        {
            int neighbour=adj[node][j].first;
            int weight=adj[node][j].second;
            if(distance[neighbour]>distance[node]+weight)
            {
                distance[neighbour]=distance[node]+weight;
                parent[neighbour]=node;
                q.push(make_pair(distance[neighbour],neighbour));
            }
        }
   
     
    }

}
int main()
{
    int V,E;
    cin>>V >> E;
    vector<pair<int,int>>adj[V];
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    vector<int>distance(V,INT_MAX);
    vector<int>visited(V,0);
    vector<int>parent(V,-1);
    Dijksra(adj,V,distance,visited,parent);

    for(auto i: distance)
    {
        cout<< i << " ";
    }

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
    for(auto i: path)
    {
        cout<<i << " ";
    }
}