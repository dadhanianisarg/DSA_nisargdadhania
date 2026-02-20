class Solution {
    long long helper(int i, int hold, vector<int>& prices,
                     vector<vector<long long>>& dp) {
        if (i == prices.size())
            return 0;
        if (dp[i][hold] != -1)
            return dp[i][hold];

        long long profit;
        if (hold) {
            long long sell = prices[i] + helper(i + 1, 0, prices, dp);
            long long hold = helper(i + 1, 1, prices, dp);
            profit = max(sell, hold);
        } else {
            long long buy = -prices[i] + helper(i + 1, 1, prices, dp);
            long long skip = helper(i + 1, 0, prices, dp);
            profit = max(buy, skip);
        }
        return dp[i][hold] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return helper(0, 0, prices, dp);
    }
};
// memory limit exceed due to storing all the states of bought instead just
// store are we hold any stokes or not class Solution {
//     int helper(int i, int bought, vector<int>& prices,
//                      vector<vector<int>>& dp) {
//         if (i == prices.size())
//             return 0;
//         if (dp[i][bought + 1] != -1)
//             return dp[i][bought + 1];
//         int profit = 0;
//         if (bought != -1) {
//             int sell =
//                 prices[i] - prices[bought] + helper(i + 1, -1, prices, dp);
//             int sellAndBuy =
//                 prices[i] - prices[bought] + helper(i + 1, i, prices, dp);
//             int hold = helper(i + 1, bought, prices, dp);
//             profit = max({sell, sellAndBuy, hold});
//         } else {
//             int buy = helper(i + 1, i, prices, dp);
//             int skip = helper(i + 1, -1, prices, dp);
//             profit = max(buy, skip);
//         }
//         return dp[i][bought + 1] = profit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return helper(0, -1, prices, dp);
//     }
// };