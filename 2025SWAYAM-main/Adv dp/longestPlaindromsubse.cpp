#include <bits/stdc++.h>
using namespace std;

// Bottom-up approach for Longest Palindromic Subsequence
int lpsBottomUp(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Single characters are palindromes of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill the dp table for lengths 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

// Top-down approach with memoization for Longest Palindromic Subsequence
int lpsTopDownHelper(string& s, int i, int j, vector<vector<int>>& memo) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (memo[i][j] != -1) return memo[i][j];

    if (s[i] == s[j]) {
        memo[i][j] = 2 + lpsTopDownHelper(s, i + 1, j - 1, memo);
    } else {
        memo[i][j] = max(lpsTopDownHelper(s, i + 1, j, memo), lpsTopDownHelper(s, i, j - 1, memo));
    }
    return memo[i][j];
}

int lpsTopDown(string s) {
    int n = s.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return lpsTopDownHelper(s, 0, n - 1, memo);
}

int main() {
    string s = "bbbab";
    cout << "Bottom-up LPS length: " << lpsBottomUp(s) << endl;
    cout << "Top-down LPS length: " << lpsTopDown(s) << endl;
    return 0;
}
