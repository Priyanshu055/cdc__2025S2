#include <bits/stdc++.h>
using namespace std;

// Top-down approach (Recursion with Memoization)
int minCostClimbingStairsTopDown(vector<int>& cost, int n, vector<int>& memo) {
    if (n == 0 || n == 1) {
        return cost[n];
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = cost[n] + min(minCostClimbingStairsTopDown(cost, n - 1, memo), minCostClimbingStairsTopDown(cost, n - 2, memo));
    return memo[n];
}

// Bottom-up approach (Iterative DP)
int minCostClimbingStairsBottomUp(vector<int>& cost) {
    int n = cost.size();
    if (n == 0) return 0;
    if (n == 1) return cost[0];
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; ++i) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    vector<int> cost = {10, 15, 20}; // Example input
    int n = cost.size();

    // Top-down
    vector<int> memo(n, -1);
    int minCostTopDown = min(minCostClimbingStairsTopDown(cost, n - 1, memo), minCostClimbingStairsTopDown(cost, n - 2, memo));
    cout << "Minimum cost (Top-down): " << minCostTopDown << endl;

    // Bottom-up
    int minCostBottomUp = minCostClimbingStairsBottomUp(cost);
    cout << "Minimum cost (Bottom-up): " << minCostBottomUp << endl;

    return 0;
}
