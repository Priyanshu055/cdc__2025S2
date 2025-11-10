#include <bits/stdc++.h>
using namespace std;

// Bottom-up approach for Longest Palindromic Substring length
int lpsBottomUp(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;

    // All substrings of length 1 are palindromes
    for(int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check for sub-string of length 2
    for(int i = 0; i < n-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            maxLen = 2;
        }
    }

    // Check for lengths greater than 2
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                maxLen = len;
            }
        }
    }
    return maxLen;
}

// Top-down approach with memoization for Longest Palindromic Substring length
int lpsTopDownHelper(string& s, int i, int j, vector<vector<int>>& memo) {
    if(i > j) return 0;
    if(i == j) return 1;
    if(memo[i][j] != -1) return memo[i][j];

    if(s[i] == s[j]) {
        int inner = lpsTopDownHelper(s, i+1, j-1, memo);
        if(inner == j - i - 1) { // inner substring is palindrome
            memo[i][j] = inner + 2;
            return inner + 2;
        } else {
            memo[i][j] = 0;
            return 0;
        }
    } else {
        memo[i][j] = 0;
        return 0;
    }
}

int lpsTopDown(string s) {
    int n = s.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int maxLen = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int len = lpsTopDownHelper(s, i, j, memo);
            if(len > maxLen) maxLen = len;
        }
    }
    return maxLen;
}

int main() {
    string s = "babad";
    cout << "Bottom-up LPS length: " << lpsBottomUp(s) << endl;
    cout << "Top-down LPS length: " << lpsTopDown(s) << endl;
    return 0;
}
