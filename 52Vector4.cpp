#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;

    // Fill the vector
    for(int i = 0; i < 10; i++)
        vec.push_back(i + 1);

    // Forward iteration using auto
    for(auto i = vec.begin(); i != vec.end(); i++)
        cout << *i << "  ";
    cout << endl;

    // Reverse iteration using auto
    for(auto ri = vec.rbegin(); ri != vec.rend(); ri++)
        cout << *ri << "  ";
    cout << endl;

    // Insert 20 at position 5
    auto i = vec.begin();
    vec.insert(i + 5, 20);

    for(auto i = vec.begin(); i != vec.end(); i++)
        cout << *i << "  ";
    cout << endl;

    // Using next and prev
    i = vec.begin();
    auto it = next(i, 1);
    cout << endl << *it;

    i = vec.end();
    auto it1 = prev(i, 2);
    cout << endl << *it1;

    return 0;
}
