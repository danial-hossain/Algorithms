#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;

    vector <int> adj[n];
    vector <int> :: iterator j;
    for(int i = 0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i<n; i++)
    {
        cout<<i<<"-> ";
        for(int j = 0; j <adj[i].size(); j++)
        {
            cout<<adj[i][j]<<"  ";
        }

        cout<<endl;
    }

    cout<<endl;

    for(int i = 0; i<n; i++)
    {
        cout<<i<<"-> ";
        for(j = adj[i].begin(); j != adj[i].end(); j++)
        {
            cout<<*j<<"  ";
        }

        cout<<endl;
    }
    return 0;
}