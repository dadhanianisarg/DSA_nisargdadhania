class Solution {
    int helper(int i1, int i2, string& text1, string& text2,
               vector<vector<int>>& dp) {
        if (i1 == text1.size() || i2 == text2.size())
            return 0;
        int match = 0;
        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        if (text1[i1] == text2[i2]) {
            match = 1 + helper(i1 + 1, i2 + 1, text1, text2, dp);
        }
        int notMatch1 = helper(i1 + 1, i2, text1, text2, dp);
        int notMatch2 = helper(i1, i2 + 1, text1, text2, dp);
        return dp[i1][i2] = max({match, notMatch1, notMatch2});
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return helper(0, 0, text1, text2, dp);
    }
};