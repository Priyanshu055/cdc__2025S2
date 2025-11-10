#include <bits/stdc++.h>
using namespace std;

// Bottom-up approach for Longest Common Subsequence
int lcsBottomUp(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// Top-down approach with memoization for Longest Common Subsequence
int lcsTopDownHelper(string s1, string s2, int i, int j, vector<vector<int>>& memo) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (s1[i - 1] == s2[j - 1]) {
        memo[i][j] = 1 + lcsTopDownHelper(s1, s2, i - 1, j - 1, memo);
    } else {
        memo[i][j] = max(lcsTopDownHelper(s1, s2, i - 1, j, memo), lcsTopDownHelper(s1, s2, i, j - 1, memo));
    }
    return memo[i][j];
}

int lcsTopDown(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return lcsTopDownHelper(s1, s2, m, n, memo);
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Bottom-up LCS length: " << lcsBottomUp(s1, s2) << endl;
    cout << "Top-down LCS length: " << lcsTopDown(s1, s2) << endl;
    return 0;
}
