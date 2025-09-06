#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<vector<int>> vect
    {
        {1},
        {4, 5},
        {7, 8, 9}
    };

    vector<vector<int>> vect1;

    vect1.push_back({1,3,9});
    vect1.push_back({1,3,9,5});
    vect1.push_back({1,3,2,9,8});

    for(vector<int>v1D : vect)
    {
        for(auto i : v1D)
        {
            cout<<i<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector <vector<int>> :: iterator row;
    row = vect1.begin();
    vect1.insert(row+2, {12, 13, 14, 15});
    for(vector<int>v1D : vect)
    {
        for(auto i : v1D)
        {
            cout<<i<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i = 0; i < vect1.size(); i++)
    {
        for(int j = 0; j < vect1[i].size(); j++)
        {
            cout<< vect1[i][j]<<"  ";
        }

        cout<<endl;
    }

    return 0;
}