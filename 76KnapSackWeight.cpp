#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

// Comparator: sort by value first, and if value equal, take larger weight
bool comp(Item a, Item b) {
    if (a.value == b.value) return a.weight < b.weight; // smaller weight first
    return a.value > b.value;
}

double fractionalKnapsack(int w, Item arr[], int n) {
    // sort items by value, then by larger weight for equal value
    sort(arr, arr + n, comp);

    double profit = 0;
    int i = 0;
    while (w && i < n) {
        if (w >= arr[i].weight) {
            profit += arr[i].value;
            w -= arr[i].weight;
        } else {
            double temp = (double)arr[i].value / arr[i].weight;
            profit += temp * w;
            w = 0;
        }
        i++;
    }
    return profit;
}

int main() {
    int W = 20;  // capacity of knapsack
    Item arr[] = { {60, 3}, {100, 5}, {200, 10}, {60, 6} };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum profit in Knapsack = "
         << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}
