#include <bits/stdc++.h>
using namespace std;

// Bottom-up Dynamic Programming Approach
int numSquaresBottomUp(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

// Top-down Dynamic Programming Approach (Recursive with Memoization)
int numSquaresTopDownHelper(int n, vector<int>& memo) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    int minCount = INT_MAX;
    for (int j = 1; j * j <= n; ++j) {
        minCount = min(minCount, numSquaresTopDownHelper(n - j * j, memo) + 1);
    }
    memo[n] = minCount;
    return minCount;
}

int numSquaresTopDown(int n) {
    vector<int> memo(n + 1, -1);
    return numSquaresTopDownHelper(n, memo);
}

int main() {
    int n = 12; // Example input
    cout << "Bottom-up approach: " << numSquaresBottomUp(n) << endl;
    cout << "Top-down approach: " << numSquaresTopDown(n) << endl;
    return 0;
}
