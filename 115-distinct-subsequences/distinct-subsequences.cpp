class Solution {
    int helper(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        int n = s.size();
        int m = t.size();
        if (j >= m)
            return 1;
        if (i >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j]) {
            int sameCombi = helper(i + 1, j + 1, s, t, dp);
            int diffCombi = helper(i + 1, j, s, t, dp);
            return dp[i][j] = sameCombi + diffCombi;
        }
        return dp[i][j] = helper(i + 1, j, s, t, dp);
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, s, t, dp);
    }
};