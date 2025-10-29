#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memo.assign(n, -1);
        return min(dp(cost, n - 1), dp(cost, n - 2));
    }

    int dp(vector<int>& cost, int i) {
        if (i < 0) return 0;
        if (i == 0 || i == 1) return cost[i];
        if (memo[i] != -1) return memo[i];
        return memo[i] = cost[i] + min(dp(cost, i - 1), dp(cost, i - 2));
    }
};

int main() {
    Solution sol;
    int size;
    cout << "Enter the number of costs: ";
    cin >> size;
    vector<int> cost(size);
    cout << "Enter costs: ";
    for (int i = 0; i < size; ++i) {
        cin >> cost[i];
    }
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
