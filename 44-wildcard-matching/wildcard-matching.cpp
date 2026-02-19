class Solution {
    bool helper(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        int n = s.size();
        int m = p.size();
        if (j == m)
            return i == n;
        if (i == n) {
            while (j < m) {
                if (p[j] != '*')
                    return false;
                j++;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        bool match = false;
        if (p[j] == s[i] || p[j] == '?')
            match = helper(i + 1, j + 1, s, p, dp);

        bool star = false;
        if (p[j] == '*')
            star = helper(i + 1, j, s, p, dp) || helper(i, j + 1, s, p, dp);
        return dp[i][j] = match || star;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, s, p, dp);
    }
};
