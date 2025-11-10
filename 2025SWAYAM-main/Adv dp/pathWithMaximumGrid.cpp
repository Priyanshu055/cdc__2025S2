#include <bits/stdc++.h>
using namespace std;

// Bottom-up Dynamic Programming Approach
int maxPathSumBottomUp(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    // Fill first row
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    // Fill first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    // Fill the rest
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

// Top-down Dynamic Programming Approach (Recursive with Memoization)
int maxPathSumTopDownHelper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
    if (i < 0 || j < 0) return INT_MIN;
    if (memo[i][j] != -1) return memo[i][j];
    if (i == 0 && j == 0) return memo[i][j] = grid[0][0];
    int up = (i > 0) ? maxPathSumTopDownHelper(i-1, j, grid, memo) : INT_MIN;
    int left = (j > 0) ? maxPathSumTopDownHelper(i, j-1, grid, memo) : INT_MIN;
    memo[i][j] = grid[i][j] + max(up, left);
    return memo[i][j];
}

int maxPathSumTopDown(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    return maxPathSumTopDownHelper(m-1, n-1, grid, memo);
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Bottom-up approach: " << maxPathSumBottomUp(grid) << endl;
    cout << "Top-down approach: " << maxPathSumTopDown(grid) << endl;
    return 0;
}
