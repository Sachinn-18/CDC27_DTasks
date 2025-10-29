#include <bits/stdc++.h>
using namespace std;

int getMaximumGold(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int right = getMaximumGold(grid, i, j+1, dp);
    int down = getMaximumGold(grid, i+1, j, dp);
    return dp[i][j] = grid[i][j] + max(right, down);
}

int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int maxGold = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0) {
                maxGold = max(maxGold, getMaximumGold(grid, i, j, dp));
            }
        }
    }
    return maxGold;
}

int main() {
    vector<vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    cout << getMaximumGold(grid) << endl;
    return 0;
}
