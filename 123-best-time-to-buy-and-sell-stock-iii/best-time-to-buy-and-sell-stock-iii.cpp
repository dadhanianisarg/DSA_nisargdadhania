class Solution {
    long long helper(int i, int hold, int cnt, vector<int>& prices,
                     vector<vector<vector<long long>>>& dp) {
        if (cnt == 2)
            return 0;
        if (i == prices.size())
            return 0;
        if (dp[i][hold][cnt] != -1)
            return dp[i][hold][cnt];

        long long profit;
        if (hold) {
            long long sell = prices[i] + helper(i + 1, 0, cnt + 1, prices, dp);
            long long hold = helper(i + 1, 1, cnt, prices, dp);
            profit = max(sell, hold);
        } else {
            long long buy = -prices[i] + helper(i + 1, 1, cnt, prices, dp);
            long long skip = helper(i + 1, 0, cnt, prices, dp);
            profit = max(buy, skip);
        }
        return dp[i][hold][cnt] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(2, vector<long long>(2, -1)));
        return helper(0, 0, 0, prices, dp);
    }
};
