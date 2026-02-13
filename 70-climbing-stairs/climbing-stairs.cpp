class Solution {
    int helper(int i, int n, vector<int>& dp) {
        if (i == n)
            return 1;
        if (i > n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int oneStep = helper(i + 1, n, dp);
        int twoStep = helper(i + 2, n, dp);
        return dp[i] = oneStep + twoStep;
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(0, n, dp);
    }
};