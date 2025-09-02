#include<iostream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v;

    for(int i = 0; i < 20; i++)
    {
        v.push_back(i+1);
        //v[i] = i+1;
    }

    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<"  ";
    }

    cout<<endl;

    cout<<"Max Size: "<<v.max_size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.resize(5);

    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<"  ";
    }
    cout<<endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout<<!v.empty()<<"  ";
    }

    cout<<endl;
    for(int i = 0; i < 10; i++)
    {
        cout<<v[i]<<"  ";
    }
    v.shrink_to_fit();

    cout<<endl;
    for(int i = 0; i < 10; i++)
    {
        cout<<v[i]<<"  ";
    }

    v.reserve(5);

    cout<<endl;
    for(int i = 0; i < 20; i++)
    {
        cout<<v[i]<<"  ";
    }
    return 0;
}