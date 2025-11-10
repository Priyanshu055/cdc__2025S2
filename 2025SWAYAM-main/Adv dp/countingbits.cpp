#include <bits/stdc++.h>
using namespace std;

// Top-down approach (Recursion with Memoization)
vector<int> countBitsTopDown(int n, vector<int>& memo) {
    if (n == 0) {
        return {0};
    }
    if (memo[n] != -1) {
        return {memo[n]};
    }
    vector<int> prev = countBitsTopDown(n - 1, memo);
    int bits = __builtin_popcount(n);
    memo[n] = bits;
    prev.push_back(bits);
    return prev;
}

// Bottom-up approach (Iterative DP)
vector<int> countBitsBottomUp(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Top-down
    vector<int> memo(n + 1, -1);
    vector<int> resultTopDown = countBitsTopDown(n, memo);
    cout << "Top-down result: ";
    for (int val : resultTopDown) {
        cout << val << " ";
    }
    cout << endl;

    // Bottom-up
    vector<int> resultBottomUp = countBitsBottomUp(n);
    cout << "Bottom-up result: ";
    for (int val : resultBottomUp) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
