#include<bits/stdc++.h>
using namespace std;
void BellmanFord(vector<vector<int>>adj,int V,int E,vector<int>&distance,bool &flag)
{
   
     distance[0]=0;
     for(int i=0;i<V-1;i++)
     {

        for(int j=0;j<E;j++)
        {
           int u=adj[j][0];
           int v=adj[j][1];
           int w=adj[j][2];
           if(distance[v]>distance[u]+w)
           {
            distance[v]=distance[u]+w;
           }
        }
     }
  
      flag=false;
        for(int j=0;j<E;j++)
        {
           int u=adj[j][0];
           int v=adj[j][1];
           int w=adj[j][2];
           if(distance[v]>distance[u]+w)
           {
            distance[v]=distance[u]+w;
            flag=true;
           }
        }
}


int main()
{
    int V,E;
    cin>>V >> E;
    vector<vector<int>>adj;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
       adj.push_back({u,v,w});
    }
    vector<int>distance(V,INT_MAX);
  bool flag;
    BellmanFord(adj,V,E,distance,flag);

    for(auto i: distance)
    {
        cout<< i<< " ";
    }
    cout<<endl;
    if(flag)
    {
        cout<<"Negative Cycle Exists ";
    }
    else
    {
        cout<<"Doesnt Have a Negative Cycle";
    }
}
