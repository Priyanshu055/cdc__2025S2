#include <bits/stdc++.h>
using namespace std;

// Top-down approach (Recursion with Memoization)
int climbStairsTopDown(int n, vector<int>& memo) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = climbStairsTopDown(n - 1, memo) + climbStairsTopDown(n - 2, memo);
    return memo[n];
}

// Bottom-up approach (Iterative DP)
int climbStairsBottomUp(int n) {
    if (n <= 1) {
        return 1;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    // Top-down
    vector<int> memo(n + 1, -1);
    int waysTopDown = climbStairsTopDown(n, memo);
    cout << "Number of ways (Top-down): " << waysTopDown << endl;

    // Bottom-up
    int waysBottomUp = climbStairsBottomUp(n);
    cout << "Number of ways (Bottom-up): " << waysBottomUp << endl;

    return 0;
}
