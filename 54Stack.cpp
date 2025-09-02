#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack <int> st;
    stack <int> st2;
    for(int i = 0; i < 10; i++)
    {
        st.push(i+1);
    }
    for(int i = 0; i < 10; i++)
    {
        st2.push(st.top());
        st.pop();
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

    while(!st2.empty())
    {
        cout<<st2.top()<<endl;
        st2.pop();
    }
    return 0;
}