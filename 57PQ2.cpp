#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue<pair<int, int> > tempPQ)
{
	while (!tempPQ.empty()) {
		cout << tempPQ.top().first << " " << tempPQ.top().second << endl;
		tempPQ.pop();
	}
	cout << endl;
}

int main()
{
	priority_queue<pair<int, int> > p1;

	p1.push(make_pair(4, 5));
	p1.push(make_pair(5, 4));
	p1.push(make_pair(1, 6));
	p1.push(make_pair(7, 3));
	p1.push(make_pair(9, 4));
	showpq(p1);
	return 0;
}
