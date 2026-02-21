class Solution {
    int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (!buy) {
            int buy = -prices[i] + helper(i + 1, 1, prices, dp);
            int skip = helper(i + 1, 0, prices, dp);
            profit = max({profit, buy, skip});
        } else {
            int sell = prices[i] + helper(i + 2, 0, prices, dp);
            int hold = helper(i + 1, 1, prices, dp);
            profit = max({profit, sell, hold});
        }
        return dp[i][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return helper(0, 0, prices, dp);
    }
};