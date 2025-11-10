#include <bits/stdc++.h>
using namespace std;

// Bottom-up approach for Egg Dropping Problem
int eggDropBottomUp(int e, int f) {
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, 0));

    // Base cases
    for (int i = 1; i <= e; i++) {
        dp[i][1] = 1; // 1 floor, 1 trial
        dp[i][0] = 0; // 0 floors, 0 trials
    }
    for (int j = 1; j <= f; j++) {
        dp[1][j] = j; // 1 egg, j floors, j trials
    }

    // Fill the dp table
    for (int i = 2; i <= e; i++) {
        for (int j = 2; j <= f; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j]) {
                    dp[i][j] = res;
                }
            }
        }
    }
    return dp[e][f];
}

// Top-down approach with memoization for Egg Dropping Problem
int eggDropTopDownHelper(int e, int f, vector<vector<int>>& memo) {
    if (f == 0 || f == 1) return f;
    if (e == 1) return f;
    if (memo[e][f] != -1) return memo[e][f];

    int minTrials = INT_MAX;
    for (int x = 1; x <= f; x++) {
        int res = 1 + max(eggDropTopDownHelper(e - 1, x - 1, memo), eggDropTopDownHelper(e, f - x, memo));
        if (res < minTrials) {
            minTrials = res;
        }
    }
    memo[e][f] = minTrials;
    return minTrials;
}

int eggDropTopDown(int e, int f) {
    vector<vector<int>> memo(e + 1, vector<int>(f + 1, -1));
    return eggDropTopDownHelper(e, f, memo);
}

int main() {
    int e = 2; // eggs
    int f = 10; // floors
    cout << "Bottom-up minimum trials: " << eggDropBottomUp(e, f) << endl;
    cout << "Top-down minimum trials: " << eggDropTopDown(e, f) << endl;
    return 0;
}
