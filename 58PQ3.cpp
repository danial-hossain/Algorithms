#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

struct compare{
    bool operator() (pi a, pi b){
         return a.second > b.second;
    }
};
// main program
int main() {
    priority_queue<pi, vector<pi>, compare> pq;
    pq.push(make_pair(10, 200));
    pq.push(make_pair(20, 100));
    pq.push(make_pair(15, 400));

    while(!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}