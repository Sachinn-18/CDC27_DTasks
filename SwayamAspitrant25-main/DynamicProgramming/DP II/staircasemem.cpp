#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) {
        memo.assign(n + 1, -1);
        return dp(n);
    }

    int dp(int n) {
        if (n <= 1) return 1;
        if (memo[n] != -1) return memo[n];
        return memo[n] = dp(n - 1) + dp(n - 2);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    cout << sol.climbStairs(n) << endl;
    return 0;
}
