class Solution {
    int helper(int i, int sum, int& amount, vector<int>& coins,
               vector<vector<int>>& dp) {
        if (sum == amount)
            return 1;
        if (i == coins.size()) {
            return 0;
        }
        if (dp[i][sum] != -1)
            return dp[i][sum];
        int take = 0;
        if (sum + coins[i] <= amount) {
            take = helper(i, sum + coins[i], amount, coins, dp);
        }
        int notTake = helper(i + 1, sum, amount, coins, dp);
        return dp[i][sum] = take + notTake;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return helper(0, 0, amount, coins, dp);
    }
};