#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a subset with given sum using DP
bool isSubsetSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j >= nums[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> nums = {3, 34, 14, 12, 5, 2};
    int target = 9;
    if (isSubsetSum(nums, target)) {
        cout << "Subset with sum " << target << " exists." << endl;
    } else {
        cout << "No subset with sum " << target << " exists." << endl;
    }
    return 0;
}
