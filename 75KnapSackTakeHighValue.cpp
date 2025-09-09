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
    return a.value  > b.value;
}

double fractionalKnapsack(int w, Item arr[], int n) {
    // sort the array on the basis of value/weight descending order
    sort(arr, arr + n, comp);

    double profit = 0;
    int i = 0;
    while (w && i < n) {
        if (w >= arr[i].weight) {
            profit += arr[i].value;
            w -= arr[i].weight;
        } else {
            double temp = arr[i].value;
            temp /= arr[i].weight;
            profit += temp * w;
            w = 0;
        }
        i++;
    }
    return profit;
}

int main() {
    int W = 50;  // capacity of knapsack
    Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum profit in Knapsack = "
         << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}
