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
    if (n == 1) return nums[0];
    vector<int> dp1(n-1, -1);
    int max1 = rob(nums, n-2, dp1);
    vector<int> dp2(n, -1);
    int max2 = rob(nums, n-1, dp2) - nums[0];
    return max(max1, max2);
}

int main() {
    vector<int> nums = {2, 4, 3};
    cout << rob(nums) << endl;
    return 0;
}
