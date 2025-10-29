// Flood Fill
// Problem: Given a 2D grid representing an image, perform flood fill starting from a given position with a new color.

#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& image, int newColor, int originalColor, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || image[i][j] != originalColor) {
        return;
    }

    image[i][j] = newColor;

    // Visit all adjacent cells
    dfs(i - 1, j, image, newColor, originalColor, rows, cols); // Up
    dfs(i + 1, j, image, newColor, originalColor, rows, cols); // Down
    dfs(i, j - 1, image, newColor, originalColor, rows, cols); // Left
    dfs(i, j + 1, image, newColor, originalColor, rows, cols); // Right
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image.empty() || image[sr][sc] == newColor) return image;

    int rows = image.size();
    int cols = image[0].size();
    int originalColor = image[sr][sc];

    dfs(sr, sc, image, newColor, originalColor, rows, cols);

    return image;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> image(rows, vector<int>(cols));
    cout << "Enter the image grid:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cout << "Enter starting row, starting column, and new color: ";
    cin >> sr >> sc >> newColor;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Image after flood fill:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
