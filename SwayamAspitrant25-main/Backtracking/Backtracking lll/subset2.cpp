#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subset2Helper(vector<int>& nums, size_t index, vector<int>& curr, vector<vector<int>>& res) {
    res.push_back(curr);
    for (size_t i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[i - 1]) continue; // skip duplicates
        curr.push_back(nums[i]);
        subset2Helper(nums, i + 1, curr, res);
        curr.pop_back();
    }
}

vector<vector<int>> subset2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> curr;
    subset2Helper(nums, 0, curr, res);
    return res;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n < 0) return 0;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result = subset2(nums);
    cout << "All unique subsets:\n";
    for (const auto& subset : result) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ",";
        }
        cout << "} ";
    }
    cout << endl;
    return 0;
}

/*
Logic: Generate all subsets while skipping duplicate elements after sorting.  
Time: O(2^n), Space: O(n).
*/
