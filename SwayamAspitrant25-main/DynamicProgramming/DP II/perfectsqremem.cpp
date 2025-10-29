#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> memo;
    int numSquares(int n) {
        memo.assign(n + 1, -1);
        return dp(n);
    }

    int dp(int n) {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];
        int minVal = INT_MAX;
        for (int i = 1; i * i <= n; ++i) {
            minVal = min(minVal, 1 + dp(n - i * i));
        }
        return memo[n] = minVal;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << sol.numSquares(n) << endl;
    return 0;
}
