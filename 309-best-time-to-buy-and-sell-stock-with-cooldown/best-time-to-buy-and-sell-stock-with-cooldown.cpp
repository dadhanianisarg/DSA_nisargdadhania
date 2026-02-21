// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n + 2, vector<int>(2, 0));

//         for (int i = n - 1; i >= 0; i--) {
//             for (int buy = 0; buy < 2; buy++) {

//                 if (buy == 0) {
//                     int buyStock = -prices[i] + dp[i + 1][1];
//                     int skip = dp[i + 1][0];
//                     dp[i][buy] = max(buyStock, skip);
//                 } else {
//                     int sellStock = prices[i] + dp[i + 2][0];
//                     int hold = dp[i + 1][1];
//                     dp[i][buy] = max(sellStock, hold);
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };

class Solution {
    int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if (buy == 0) {
            int buyStock = -prices[i] + helper(i + 1, 1, prices, dp);
            int skip = helper(i + 1, 0, prices, dp);
            profit = max(buyStock, skip);
        } else {
            int sellStock = prices[i] + helper(i + 2, 0, prices, dp);
            int hold = helper(i + 1, 1, prices, dp);
            profit = max(sellStock, hold);
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