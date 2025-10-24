#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0;

    for (auto& it : items) {
        if (W >= it.weight) {
            totalValue += it.value;
            W -= it.weight;
        } else {
            totalValue += it.value * ((double)W / it.weight);
            break;
        }
    }
    return totalValue;
}
int main() {
    int W = 50; // Maximum weight of knapsack
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}