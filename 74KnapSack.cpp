#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

bool comp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, comp);

    double profit = 0.0;
    int i = 0;

    cout << "Weights taken: ";

    while (W && i < n) {
        if (W >= arr[i].weight) {
            profit += arr[i].value;
            W -= arr[i].weight;
            cout << arr[i].weight << " ";   // print full weight taken
        } else {
            double ratio = (double)arr[i].value / arr[i].weight;
            profit += ratio * W;
            cout << W << " ";   // print only fraction of weight taken
            W = 0;
        }
        i++;
    }

    cout << endl;
    return profit;
}

int main() {
    int W = 50;
    Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxProfit = fractionalKnapsack(W, arr, n);

    cout << "Maximum profit in Knapsack = " << maxProfit << endl;

    return 0;
}
