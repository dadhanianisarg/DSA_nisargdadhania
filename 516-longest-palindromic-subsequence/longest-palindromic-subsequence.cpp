class Solution {
    int helper(int l, int r, string& s, vector<vector<int>>& dp) {
        if (l < 0 || r >= s.size())
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int match = 0;
        int notMatch1 = 0;
        int notMatch2 = 0;
        if (s[l] == s[r] && l == r)
            match = 1 + helper(l - 1, r + 1, s, dp);
        else if (s[l] == s[r]) {
            match = 2 + helper(l - 1, r + 1, s, dp);
        } else {
            notMatch1 = helper(l - 1, r, s, dp);
            notMatch2 = helper(l, r + 1, s, dp);
        }
        return dp[l][r] = max({match, notMatch1, notMatch2});
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 1)
            return 1;
        int ans = 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++) {
            ans = max(ans, helper(i, i, s, dp));
            ans = max(ans, helper(i, i + 1, s, dp));
        }
        return ans;
    }
};
