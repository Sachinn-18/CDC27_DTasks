#include <bits/stdc++.h>
using namespace std;

int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxGold = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) continue;
            int up = (i > 0) ? dp[i-1][j] : 0;
            int left = (j > 0) ? dp[i][j-1] : 0;
            dp[i][j] = grid[i][j] + max(up, left);
            maxGold = max(maxGold, dp[i][j]);
        }
    }
    return maxGold;
}

int main() {
    vector<vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    cout << getMaximumGold(grid) << endl;
    return 0;
}
