class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][m] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return (int)dp[0][0];
    }
};

// class Solution {
//     int helper(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
//         int n = s.size();
//         int m = t.size();
//         if (j >= m)
//             return 1;
//         if (i >= n)
//             return 0;
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (s[i] == t[j]) {
//             int sameCombi = helper(i + 1, j + 1, s, t, dp);
//             int diffCombi = helper(i + 1, j, s, t, dp);
//             return dp[i][j] = sameCombi + diffCombi;
//         }
//         return dp[i][j] = helper(i + 1, j, s, t, dp);
//     }

// public:
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//         return helper(0, 0, s, t, dp);
//     }
// };