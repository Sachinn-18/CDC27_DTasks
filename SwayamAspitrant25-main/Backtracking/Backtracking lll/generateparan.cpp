#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateParenthesesHelper(int open, int close, int n, string &curr, vector<string>& res) {
    if (curr.size() == 2 * (size_t)n) {
        res.push_back(curr);
        return;
    }
    if (open < n) {
        curr.push_back('(');
        generateParenthesesHelper(open + 1, close, n, curr, res);
        curr.pop_back();
    }
    if (close < open) {
        curr.push_back(')');
        generateParenthesesHelper(open, close + 1, n, curr, res);
        curr.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string curr;
    curr.reserve(2 * max(0, n));
    generateParenthesesHelper(0, 0, n, curr, res);
    return res;
}
int main() {
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;
    vector<string> result = generateParenthesis(n);
    cout << "Generated Parentheses Combinations:\n";
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}

/*
Logic: Use backtracking to ensure number of '(' never less than ')'.  
Time: O(2^n) but only valid combos generated.
*/
