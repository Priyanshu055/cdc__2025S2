#include <bits/stdc++.h>
using namespace std;

// Bottom-up Dynamic Programming Approach
int maxGoldBottomUp(vector<vector<int>>& gold) {
    int m = gold.size();
    if (m == 0) return 0;
    int n = gold[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // Fill the last column
    for (int i = 0; i < m; ++i) {
        dp[i][n-1] = gold[i][n-1];
    }
    // Fill from right to left
    for (int j = n-2; j >= 0; --j) {
        for (int i = 0; i < m; ++i) {
            int right = dp[i][j+1];
            int right_up = (i > 0) ? dp[i-1][j+1] : 0;
            int right_down = (i < m-1) ? dp[i+1][j+1] : 0;
            dp[i][j] = gold[i][j] + max({right, right_up, right_down});
        }
    }
    // Find the maximum in the first column
    int maxGold = 0;
    for (int i = 0; i < m; ++i) {
        maxGold = max(maxGold, dp[i][0]);
    }
    return maxGold;
}

// Top-down Dynamic Programming Approach (Recursive with Memoization)
int maxGoldTopDownHelper(int i, int j, vector<vector<int>>& gold, vector<vector<int>>& memo) {
    int m = gold.size();
    int n = gold[0].size();
    if (i < 0 || i >= m || j >= n) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int right = maxGoldTopDownHelper(i, j+1, gold, memo);
    int right_up = maxGoldTopDownHelper(i-1, j+1, gold, memo);
    int right_down = maxGoldTopDownHelper(i+1, j+1, gold, memo);
    memo[i][j] = gold[i][j] + max({right, right_up, right_down});
    return memo[i][j];
}

int maxGoldTopDown(vector<vector<int>>& gold) {
    int m = gold.size();
    if (m == 0) return 0;
    int n = gold[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    int maxGold = 0;
    for (int i = 0; i < m; ++i) {
        maxGold = max(maxGold, maxGoldTopDownHelper(i, 0, gold, memo));
    }
    return maxGold;
}

int main() {
    vector<vector<int>> gold = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    cout << "Bottom-up approach: " << maxGoldBottomUp(gold) << endl;
    cout << "Top-down approach: " << maxGoldTopDown(gold) << endl;
    return 0;
}
