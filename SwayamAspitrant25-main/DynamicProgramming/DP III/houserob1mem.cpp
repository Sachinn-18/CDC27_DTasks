#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums, int n, vector<int>& dp) {
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];
    return dp[n] = max(rob(nums, n-1, dp), nums[n] + rob(nums, n-2, dp));
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, -1);
    return rob(nums, n-1, dp);
}

int main() {
    vector<int> nums = {1, 2, 3, 2};
    cout << rob(nums) << endl;
    return 0;
}
