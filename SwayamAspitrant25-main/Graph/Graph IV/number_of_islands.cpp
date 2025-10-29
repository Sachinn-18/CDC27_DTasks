#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& grid, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
        return;
    }

    grid[i][j] = '0'; // Mark as visited

    // Visit all adjacent cells
    dfs(i - 1, j, grid, rows, cols); // Up
    dfs(i + 1, j, grid, rows, cols); // Down
    dfs(i, j - 1, grid, rows, cols); // Left
    dfs(i, j + 1, grid, rows, cols); // Right
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
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

    vector<vector<char>> grid(rows, vector<char>(cols));

    cout << "Enter the grid (0 for water, 1 for land):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int islands = numIslands(grid);
    cout << "Number of islands: " << islands << endl;

    return 0;
}
