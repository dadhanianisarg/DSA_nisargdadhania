class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string ss = s;
        reverse(s.begin(), s.end());
        int n1 = ss.size();
        int n2 = s.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i1 = n1 - 1; i1 >= 0; i1--) {
            for (int i2 = n2 - 1; i2 >= 0; i2--) {
                int match = 0;
                if (ss[i1] == s[i2])
                    match = 1 + dp[i1 + 1][i2 + 1];
                int notMatch1 = dp[i1 + 1][i2];
                int notMatch2 = dp[i1][i2 + 1];
                dp[i1][i2] = max({match, notMatch1, notMatch2});
            }
        }
        return dp[0][0];
    }
};



// tabulation of below given memo
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {

//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         for (int i = 0; i < n; i++)
//             dp[i][i] = 1;

//         for (int len = 2; len <= n; len++) {
//             for (int l = 0; l + len - 1 < n; l++) {
//                 int r = l + len - 1;
//                 if (s[l] == s[r]) {
//                     if (len == 2)
//                         dp[l][r] = 2;
//                     else
//                         dp[l][r] = 2 + dp[l + 1][r - 1];
//                 } else {
//                     dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
//                 }
//             }
//         }
//         return dp[0][n - 1];
//     }
// };

// memoization
// class Solution {
//     int helper(int l, int r, string& s, vector<vector<int>>& dp) {
//         if (l < 0 || r >= s.size())
//             return 0;
//         if (dp[l][r] != -1)
//             return dp[l][r];
//         int match = 0;
//         int notMatch1 = 0;
//         int notMatch2 = 0;
//         if (s[l] == s[r] && l == r)
//             match = 1 + helper(l - 1, r + 1, s, dp);
//         else if (s[l] == s[r]) {
//             match = 2 + helper(l - 1, r + 1, s, dp);
//         } else {
//             notMatch1 = helper(l - 1, r, s, dp);
//             notMatch2 = helper(l, r + 1, s, dp);
//         }
//         return dp[l][r] = max({match, notMatch1, notMatch2});
//     }

// public:
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         if (n == 1)
//             return 1;
//         int ans = 1;
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
//         for (int i = 0; i < n; i++) {
//             ans = max(ans, helper(i, i, s, dp));
//             ans = max(ans, helper(i, i + 1, s, dp));
//         }
//         return ans;
//     }
// };
