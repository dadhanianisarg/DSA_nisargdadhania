class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for (int j = m - 1; j >= 0; j--) {
            if (p[j] == '*')
                dp[n][j] = dp[n][j + 1];
            else
                dp[n][j] = false;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (p[j] == s[i] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};

// class Solution {
//     bool helper(int i, int j, string& s, string& p, vector<vector<int>>& dp)
//     {
//         int n = s.size();
//         int m = p.size();
//         if (j == m)
//             return i == n;
//         if (i == n) {
//             while (j < m) {
//                 if (p[j] != '*')
//                     return false;
//                 j++;
//             }
//             return true;
//         }
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         bool match = false;
//         if (p[j] == s[i] || p[j] == '?')
//             match = helper(i + 1, j + 1, s, p, dp);

//         bool star = false;
//         if (p[j] == '*')
//             star = helper(i + 1, j, s, p, dp) || helper(i, j + 1, s, p, dp);
//         return dp[i][j] = match || star;
//     }

// public:
//     bool isMatch(string s, string p) {
//         int n = s.size();
//         int m = p.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//         return helper(0, 0, s, p, dp);
//     }
// };
