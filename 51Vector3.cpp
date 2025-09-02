#include<iostream>
#include<vector>
//#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> vec;
    vector <int> :: iterator i;
    vector <int> :: reverse_iterator ri;

    for(int i = 0; i < 10; i++)
    {
        vec.push_back(i+1);
    }

    for(i = vec.begin(); i != vec.end(); i++)
    {
        cout<< *i << "  ";
    }

    cout<<endl;

    for(ri = vec.rbegin(); ri != vec.rend(); ri++)
    {
        cout<< *ri << "  ";
    }

    cout<<endl;

    //vec.assign(5,20);
    i = vec.begin();
    //vec.erase(i+5);
    vec.insert(i+5,20);
    for(i = vec.begin(); i != vec.end(); i++)
    {
        cout<< *i << "  ";
    }

    cout<<endl;
    /*vec.assign(5,20);
    for(i = vec.begin(); i != vec.end(); i++)
    {
        cout<< *i << "  ";
    }
    cout<<endl;*/

    i = vec.begin();
    auto it = next(i,1);
    cout<<endl<<*it;

    i = vec.end();
    auto it1 = prev(i,2);
    cout<<endl<<*it1;
    return 0;
}