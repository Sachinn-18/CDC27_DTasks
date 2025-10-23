#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    if (amount < 0) return -1;
    if (amount == 0) return 0;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5, 10};
    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);
    if (result == -1)
        cout << "Cannot make the given amount with provided coins.\n";
    else
        cout << "Minimum coins required: " << result << '\n';

    return 0;
}
