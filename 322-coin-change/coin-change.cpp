class Solution {
    int helper(int i, int sum, int amount, vector<int>& coins,
               vector<vector<int>>& dp) {
        if (sum == amount)
            return 0;
        if (i == coins.size() || sum > amount)
            return INT_MAX;

        if (dp[i][sum] != -1)
            return dp[i][sum];
        int take = INT_MAX;
        if (sum + coins[i] <= amount) {
            int res = helper(i, sum + coins[i], amount, coins, dp);
            if (res != INT_MAX)
                take = 1 + res;
        }

        int notTake = helper(i + 1, sum, amount, coins, dp);
        return dp[i][sum] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount , -1));

        int ans = helper(0, 0, amount, coins, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
