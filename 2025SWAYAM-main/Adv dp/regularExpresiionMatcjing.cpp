#include <bits/stdc++.h>
using namespace std;

// Top-down approach (Memoization)
class SolutionTopDown {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return helper(0, 0, s, p, memo);
    }

private:
    bool helper(int i, int j, string& s, string& p, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) return memo[i][j];
        if (j == p.size()) return i == s.size();

        bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // '*' matches zero or more of the preceding element
            memo[i][j] = helper(i, j + 2, s, p, memo) || (first_match && helper(i + 1, j, s, p, memo));
        } else {
            memo[i][j] = first_match && helper(i + 1, j + 1, s, p, memo);
        }

        return memo[i][j];
    }
};

// Bottom-up approach (Tabulation)
class SolutionBottomUp {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, etc. for empty string
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' matches zero occurrence of preceding element
                    dp[i][j] = dp[i][j - 2];
                    // '*' matches one or more occurrence if preceding matches
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    SolutionTopDown topDown;
    SolutionBottomUp bottomUp;

    string s = "aa";
    string p = "a*";

    cout << "Top-down result: " << (topDown.isMatch(s, p) ? "true" : "false") << endl;
    cout << "Bottom-up result: " << (bottomUp.isMatch(s, p) ? "true" : "false") << endl;

    return 0;
}
