#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> v1
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    v1.push_back({1, 0, 1});
	v1.push_back({0, 1});
	v1.push_back({1, 0, 1});
	for(int i = 0; i < v1.size(); i++)
    {
        for(int j = 0; j < v1[i].size(); j++)
        {
            cout<<v1[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<endl;

    /*vector<vector<int>> v2;
    for(int i = 0; i < 3; i++)
    {
        v2.push_back(vector<int>());
        for(int j = 0; j < 5; j++)
        {
            v2[i].push_back(i+1);
        }
    }

    for(int i = 0; i < v2.size(); i++)
    {
        for(int j = 0; j < v2[i].size(); j++)
        {
            cout<<v2[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    vector <vector<int>> :: iterator row;
    vector <int> :: iterator col;
    for(row = v1.begin(); row != v1.end(); row++)
    {
        for(col = row->begin(); col != row->end(); col++)
        {
            cout<<*col<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    row = v1.begin();
    v1.insert(row+3,{11,12,13,14});
    for(row = v1.begin(); row != v1.end(); row++)
    {
        for(col = row->begin(); col != row->end(); col++)
        {
            cout<<*col<<" ";
        }
        cout<<endl;
    }


    return 0;
}