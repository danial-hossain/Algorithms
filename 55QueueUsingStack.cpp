#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack <int> stk;
    stack <int> stk2;
    //stk.push(10);
    //stk.push(12);

    for(int i = 0; i < 10; i++)
    {
        stk.push(i+1);
    }

    //cout<<stk.top()<<"  "<<endl;

    while(!stk.empty())
    {
        cout<<stk.top()<< "  ";
        stk2.push(stk.top());
        stk.pop();
    }

    cout<<endl;

    while(!stk2.empty())
    {
        cout<<stk2.top()<< "  ";
        stk2.pop();
    }
    return 0;
}