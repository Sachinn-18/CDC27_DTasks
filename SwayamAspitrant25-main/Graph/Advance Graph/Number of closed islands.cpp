// Number of Closed Islands
// Problem: Given a 2D grid consisting of 0s (land) and 1s (water), count the number of closed islands.
// A closed island is an island (group of 0s) that is completely surrounded by water (1s) and not touching the boundary.

#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& grid, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 1) {
        return;
    }

    grid[i][j] = 1; // Mark as visited (change to water)

    // Visit all adjacent cells
    dfs(i - 1, j, grid, rows, cols); // Up
    dfs(i + 1, j, grid, rows, cols); // Down
    dfs(i, j - 1, grid, rows, cols); // Left
    dfs(i, j + 1, grid, rows, cols); // Right
}

int closedIsland(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();

    // First, mark all boundary-connected lands as visited (not closed)
    for (int i = 0; i < rows; i++) {
        if (grid[i][0] == 0) dfs(i, 0, grid, rows, cols); // Left boundary
        if (grid[i][cols - 1] == 0) dfs(i, cols - 1, grid, rows, cols); // Right boundary
    }
    for (int j = 0; j < cols; j++) {
        if (grid[0][j] == 0) dfs(0, j, grid, rows, cols); // Top boundary
        if (grid[rows - 1][j] == 0) dfs(rows - 1, j, grid, rows, cols); // Bottom boundary
    }

    // Now, count the remaining islands (closed ones)
    int count = 0;
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            if (grid[i][j] == 0) {
                count++;
                dfs(i, j, grid, rows, cols);
            }
        }
    }

    return count;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter the grid (0 for land, 1 for water):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int closedIslands = closedIsland(grid);
    cout << "Number of closed islands: " << closedIslands << endl;

    return 0;
}
