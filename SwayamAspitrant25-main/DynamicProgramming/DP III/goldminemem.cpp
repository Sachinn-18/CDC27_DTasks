#include <bits/stdc++.h>
using namespace std;

int maxGold(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int right = maxGold(grid, i, j+1, dp);
    int up = maxGold(grid, i-1, j+1, dp);
    int down = maxGold(grid, i+1, j+1, dp);
    int mx = right;
    if (up > mx) mx = up;
    if (down > mx) mx = down;
    return dp[i][j] = grid[i][j] + mx;
}

int maxGoldHelper(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int maxGoldVal = 0;
    for (int i = 0; i < m; i++) {
        maxGoldVal = max(maxGoldVal, maxGold(grid, i, 0, dp));
    }
    return maxGoldVal;
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1, 5}, {2, 2, 4, 1}, {5, 0, 2, 3}, {0, 6, 1, 2}};
    cout << maxGoldHelper(grid) << endl;
    return 0;
}
