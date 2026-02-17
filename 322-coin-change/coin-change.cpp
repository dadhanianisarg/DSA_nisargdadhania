class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dp[i][amount] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int sum = amount - 1; sum >= 0; sum--) {
                int take = INT_MAX;
                if ((coins[i] <= amount - sum) &&
                    dp[i][sum + coins[i]] != INT_MAX) {
                    take = 1 + dp[i][sum + coins[i]];
                }
                int notTake = dp[i + 1][sum];
                dp[i][sum] = min(take, notTake);
            }
        }
        int ans = dp[0][0];
        return (ans == INT_MAX) ? -1 : ans;
    }
};

// class Solution {
//     int helper(int i, int sum, int amount, vector<int>& coins,
//                vector<vector<int>>& dp) {
//         if (sum == amount)
//             return 0;
//         if (i == coins.size() || sum > amount)
//             return INT_MAX;

//         if (dp[i][sum] != -1)
//             return dp[i][sum];
//         int take = INT_MAX;
//         if (sum + coins[i] <= amount) {
//             int res = helper(i, sum + coins[i], amount, coins, dp);
//             if (res != INT_MAX)
//                 take = 1 + res;
//         }

//         int notTake = helper(i + 1, sum, amount, coins, dp);
//         return dp[i][sum] = min(take, notTake);
//     }

// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.rbegin(), coins.rend());
//         int n = coins.size();

//         vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

//         int ans = helper(0, 0, amount, coins, dp);
//         return (ans == INT_MAX) ? -1 : ans;
//     }
// };
