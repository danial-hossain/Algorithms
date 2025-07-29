#include<bits/stdc++.h>
using namespace std;
void DijkStraTotalSP(vector<pair<int,int>>adj[],int V,vector<int>&visited,vector<int>&distance,vector<int>&parent)
{
    int count=V;

    distance[0]=0;

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
            int neighbour=adj[node][i].first;
            int weight=adj[node][i].second;
            if(!visited[adj[node][i].first] && distance[neighbour]>distance[node] +weight)
            {
                  distance[neighbour]=distance[node] +weight;

                  parent[neighbour] = node;

            }

        }
        count--;
    }
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
        adj[v].push_back(make_pair(u,w));

    }
    vector<int>distance(V,INT_MAX);
    vector<int>visited(V,0);
    vector<int>parent(V,-1);
    DijkStraTotalSP(adj,V,visited,distance,parent);
    for(auto i: distance)
    {
        cout<<i<< " ";
    }
    cout<<endl;
    cout<<"Enter the vertices we need distances ";
    int n,m;
    cin>>n >>m;
    cout<<distance[m];
    cout<<endl;
    cout<<"Enter the destination node : " <<endl;
    int des;
    cin>>des;
    vector<int>path;
    cout<<endl;

    while(parent[des]!=-1)
    {
       path.push_back(des);
        des=parent[des];
    }

    path.push_back(des);

    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<path.size();

}