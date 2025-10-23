#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

bool solveSudokuBacktrack(vector<vector<char>>& board, array<array<bool,10>,9>& rowUsed,
                          array<array<bool,10>,9>& colUsed, array<array<bool,10>,9>& boxUsed, int idx) {
    if (idx == 81) return true;
    int r = idx / 9;
    int c = idx % 9;
    if (board[r][c] != '.') return solveSudokuBacktrack(board, rowUsed, colUsed, boxUsed, idx + 1);

    int boxIdx = (r / 3) * 3 + (c / 3);
    for (char ch = '1'; ch <= '9'; ++ch) {
        int d = ch - '0';
        if (!rowUsed[r][d] && !colUsed[c][d] && !boxUsed[boxIdx][d]) {
            board[r][c] = ch;
            rowUsed[r][d] = colUsed[c][d] = boxUsed[boxIdx][d] = true;
            if (solveSudokuBacktrack(board, rowUsed, colUsed, boxUsed, idx + 1)) return true;
            board[r][c] = '.';
            rowUsed[r][d] = colUsed[c][d] = boxUsed[boxIdx][d] = false;
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    array<array<bool,10>,9> rowUsed = {};
    array<array<bool,10>,9> colUsed = {};
    array<array<bool,10>,9> boxUsed = {};

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char ch = board[i][j];
            if (ch != '.') {
                int d = ch - '0';
                int boxIdx = (i / 3) * 3 + (j / 3);
                rowUsed[i][d] = true;
                colUsed[j][d] = true;
                boxUsed[boxIdx][d] = true;
            }
        }
    }
    solveSudokuBacktrack(board, rowUsed, colUsed, boxUsed, 0);
}

int main() {
    vector<vector<char>> board(9, vector<char>(9, '.'));
    cout << "Enter Sudoku board (9 rows of 9 characters, use '.' for empty). You can type rows without spaces:\n";
    string line;
    for (int i = 0; i < 9; ++i) {
        if (!(cin >> line) || line.size() < 9) {
            cerr << "Invalid input format\n";
            return 1;
        }
        for (int j = 0; j < 9; ++j) board[i][j] = line[j];
    }

    solveSudoku(board);

    cout << "Solved Sudoku board:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) cout << cell << ' ';
        cout << '\n';
    }
    return 0;
}

/*
Logic: Check valid placement for each empty cell recursively using backtracking.  
Time: O(9^n) worst-case, optimized by pruning invalid branches.
*/