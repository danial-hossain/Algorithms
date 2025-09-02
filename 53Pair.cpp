#include <iostream>
#include <utility>
using namespace std;

int main()
{
    pair<int, char> p;
    pair<int, string> p2 = {30, "AUST"};
    cout << p2.first << " " << p2.second; // Output: 30 AUST

    pair<int, string> p2(30, "AUST");

    p.first = 300;
    p.second = 'A';

    cout << p.first << "  " << p.second << endl;
    cout << p2.first << "  " << p2.second << endl;

    p = make_pair(50, 'D');
    cout << p.first << "  " << p.second << endl;

    pair<int, string> p3(p2);
    cout << p2.first << "  " << p2.second << endl;

    // pair withing pair

    pair<string, pair<int, char>> p4;
    p4 = make_pair("Anika", make_pair(80, 'A'));

    cout << p4.first << "  " << p4.second.first << "  " << p4.second.second << endl;
    ;

    pair<pair<string, int>, char> p5;
    p5 = make_pair(make_pair("Anika", 80), 'A');

    cout << p5.first.first << "  " << p5.first.second << "  " << p5.second << endl;
    ;

    return 0;
}