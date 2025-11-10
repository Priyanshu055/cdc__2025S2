#include <bits/stdc++.h>
using namespace std;

// Bottom-up Dynamic Programming Approach
bool canJumpBottomUp(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        if (dp[i]) {
            for (int j = 1; j <= nums[i] && i + j < n; ++j) {
                dp[i + j] = true;
            }
        }
    }
    return dp[n - 1];
}

// Top-down Dynamic Programming Approach (Recursive with Memoization)
bool canJumpTopDownHelper(int i, vector<int>& nums, vector<int>& memo) {
    if (i >= nums.size() - 1) return true;
    if (memo[i] != -1) return memo[i] == 1;
    for (int j = 1; j <= nums[i]; ++j) {
        if (canJumpTopDownHelper(i + j, nums, memo)) {
            memo[i] = 1;
            return true;
        }
    }
    memo[i] = 0;
    return false;
}

bool canJumpTopDown(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return canJumpTopDownHelper(0, nums, memo);
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4}; // Example input
    cout << "Bottom-up approach: " << (canJumpBottomUp(nums) ? "true" : "false") << endl;
    cout << "Top-down approach: " << (canJumpTopDown(nums) ? "true" : "false") << endl;
    return 0;
}
