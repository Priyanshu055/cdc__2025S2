#include <bits/stdc++.h>
using namespace std;

// Bottom-up Dynamic Programming Approach
int coinChangeBottomUp(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

// Top-down Dynamic Programming Approach (Recursive with Memoization)
int coinChangeTopDownHelper(vector<int>& coins, int amount, vector<int>& memo) {
    if (amount < 0) return -1;
    if (amount == 0) return 0;
    if (memo[amount] != -1) return memo[amount];
    int minCoins = INT_MAX;
    for (int coin : coins) {
        int res = coinChangeTopDownHelper(coins, amount - coin, memo);
        if (res != -1) {
            minCoins = min(minCoins, res + 1);
        }
    }
    memo[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
    return memo[amount];
}

int coinChangeTopDown(vector<int>& coins, int amount) {
    vector<int> memo(amount + 1, -1);
    return coinChangeTopDownHelper(coins, amount, memo);
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Bottom-up approach: " << coinChangeBottomUp(coins, amount) << endl;
    cout << "Top-down approach: " << coinChangeTopDown(coins, amount) << endl;
    return 0;
}
