#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution sol;
    int size;
    cout << "Enter the number of costs:";
    cin >> size;
    vector<int> cost(size);
    cout << "Enter costs: ";
    for (int i = 0; i < size; ++i) {
        cin >> cost[i];
    }
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
