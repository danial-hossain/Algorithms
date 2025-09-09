#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

// Custom comparator for priority_queue (based on value/weight ratio)
bool operator<(pair<int,int> a, pair<int,int> b) {
    if (a.first * b.second < b.first * a.second)
        return true;
    return false;
}

class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        double profit = 0.0;
        vector<pair<int,int>> a;

        // Store {value, weight} pairs
        for (int i = 0; i < n; i++) {
            a.push_back({arr[i].value, arr[i].weight});
        }

        // Priority queue sorted by value/weight ratio
        priority_queue<pair<int,int>> pq(a.begin(), a.end());

        while (!pq.empty() && W > 0) {
            int value = pq.top().first;
            int weight = pq.top().second;
            pq.pop();

            if (weight <= W) {
                profit += value;
                W -= weight;
            } else {
                double temp = (double)value * ((double)W / (double)weight);
                profit += temp;
                W = 0;
            }
        }
        return profit;
    }
};

// Driver Code
int main() {
    int n = 3; // Number of items
    int W = 50; // Capacity of knapsack

    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    Solution ob;
    double ans = ob.fractionalKnapsack(W, arr, n);
    cout << "Maximum value we can obtain = " << fixed << setprecision(6) << ans << endl;

    return 0;
}
