#include <bits/stdc++.h>
using namespace std;

int maxGold(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (j == 0) {
                dp[i][j] = grid[i][j];
            } else {
                int up = (i > 0) ? dp[i-1][j-1] : 0;
                int left = dp[i][j-1];
                int down = (i < m-1) ? dp[i+1][j-1] : 0;
                dp[i][j] = grid[i][j] + max({up, left, down});
            }
        }
    }
    int maxGold = 0;
    for (int i = 0; i < m; i++) {
        maxGold = max(maxGold, dp[i][n-1]);
    }
    return maxGold;
}

int main() {
    vector<vector<int>> grid = {{1, 2, 1, 5}, {2, 2, 4, 1}, {5, 0, 2, 3}, {0, 6, 1, 2}};
    cout << maxGold(grid) << endl;
    return 0;
}
