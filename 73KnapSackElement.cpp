#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and value
struct Item {
    int value, weight, index;
    Item(int value, int weight, int index) {
        this->value = value;
        this->weight = weight;
        this->index = index;
    }
};

// Comparison function to sort items by value/weight ratio
bool comp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

// Function to get maximum profit and show which items we take
double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items based on value/weight ratio
    sort(arr, arr + n, comp);

    double profit = 0.0;  // Total profit
    int i = 0;

    cout << "Items taken:\n";

    while (W && i < n) {
        if (W >= arr[i].weight) {
            // Take the whole item
            profit += arr[i].value;
            W -= arr[i].weight;
            cout << "Item " << arr[i].index 
                 << " (value=" << arr[i].value 
                 << ", weight=" << arr[i].weight << ") -> FULL\n";
        } else {
            // Take fractional part of the item
            double ratio = (double)arr[i].value / arr[i].weight;
            profit += ratio * W;
            cout << "Item " << arr[i].index 
                 << " (value=" << arr[i].value 
                 << ", weight=" << arr[i].weight << ") -> "
                 << fixed << setprecision(2) 
                 << (double)W / arr[i].weight * 100 << "%\n";
            W = 0;
        }
        i++;
    }

    return profit;
}

// Driver code
int main() {
    int W = 50;  // Capacity of knapsack
    Item arr[] = { {60, 10, 1}, {100, 20, 2}, {120, 30, 3} };
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxProfit = fractionalKnapsack(W, arr, n);

    cout << "\nMaximum profit in Knapsack = " << maxProfit << endl;

    return 0;
}
