#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> memo;
    vector<int> countBits(int n) {
        memo.assign(n + 1, -1);
        vector<int> res(n + 1);
        for (int i = 0; i <= n; ++i) {
            res[i] = dp(i);
        }
        return res;
    }

    int dp(int n) {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];
        if (n % 2 == 0) {
            return memo[n] = dp(n / 2);
        } else {
            return memo[n] = dp(n / 2) + 1;
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter N: ";
    cin >> n;
    vector<int> res = sol.countBits(n);
    for (int num : res) cout << num << " ";
    cout << endl;
    return 0;
}
