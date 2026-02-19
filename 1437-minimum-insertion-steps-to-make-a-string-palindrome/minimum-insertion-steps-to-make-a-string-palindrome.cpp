class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {
                if (s[l] == s[r]) {
                    dp[l][r] = dp[l + 1][r - 1];
                } else {
                    int leftInsert = 1 + dp[l][r - 1];
                    int rightInsert = 1 + dp[l + 1][r];
                    dp[l][r] = min(leftInsert, rightInsert);
                }
            }
        }
        return dp[0][n - 1];
    }
};

// class Solution {
//     int helper(int l, int r, string& s, vector<vector<int>>& dp) {
//         if (l >= r)
//             return 0;
//         if (dp[l][r] != -1)
//             return dp[l][r];
//         if (s[l] == s[r]) {
//             return helper(l + 1, r - 1, s, dp);
//         }
//         int leftInsert = 1 + helper(l, r - 1, s, dp);
//         int rightInsert = 1 + helper(l + 1, r, s, dp);
//         return dp[l][r] = min(leftInsert, rightInsert);
//     }

// public:
//     int minInsertions(string s) {
//         int l = 0, r = s.size() - 1;
//         vector<vector<int>> dp(r + 2, vector<int>(r + 2, -1));
//         return helper(l, r, s, dp);
//     }
// };