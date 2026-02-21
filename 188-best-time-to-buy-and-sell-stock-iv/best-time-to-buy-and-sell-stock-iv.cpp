class Solution {
    int helper(int i, int buy, int cnt, int& k, vector<int>& prices,
               vector<vector<vector<int>>>& dp) {
        if (cnt == k)
            return 0;
        if (i == prices.size())
            return 0;
        if (dp[i][buy][cnt] != -1)
            return dp[i][buy][cnt];
        int profit = 0;
        if (!buy) {
            int buy = -prices[i] + helper(i + 1, 1, cnt, k, prices, dp);
            int skip = helper(i + 1, 0, cnt, k, prices, dp);
            profit = max({profit, buy, skip});
        } else {
            int hold = helper(i + 1, 1, cnt, k, prices, dp);
            int sell = prices[i] + helper(i + 1, 0, cnt + 1, k, prices, dp);
            profit = max({profit, hold, sell});
        }
        return dp[i][buy][cnt] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(0, 0, 0, k, prices, dp);
    }
};