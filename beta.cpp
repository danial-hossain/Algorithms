#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M,X;
    int comb=0;
    cin>>N>>M>>X;
    vector<int>p(N);
     vector<int>q(M);
    for(int i=0;i<N;i++)
    {
       cin>>p[i];
    }
  for(int j=0;j<M;j++)
  {
    cin>>q[j];
  }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(p[i]+q[j]<=X)
            {
                comb++;
            }
        }
    }
    cout<<comb;

}
