class Solution {
    bool helper(int i, int j, int len, string& s1, string& s2,
                vector<vector<vector<int>>>& dp) {
        if (dp[i][j][len] != -1)
            return dp[i][j][len];
        if (s1.substr(i, len) == s2.substr(j, len))
            return dp[i][j][len] = true;
        vector<int> freq(26, 0);
        for (int k = 0; k < len; k++) {
            freq[s1[i + k] - 'a']++;
            freq[s2[j + k] - 'a']--;
        }
        for (int x = 0; x < 26; x++) {
            if (freq[x] != 0)
                return dp[i][j][len] = false;
        }
        for (int split = 1; split < len; split++) {
            // No Swap
            if (helper(i, j, split, s1, s2, dp) &&
                helper(i + split, j + split, len - split, s1, s2, dp)) {
                return dp[i][j][len] = true;
            }
            // Swap
            if (helper(i, j + len - split, split, s1, s2, dp) &&
                helper(i + split, j, len - split, s1, s2, dp)) {
                return dp[i][j][len] = true;
            }
        }
        return dp[i][j][len] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        int n = s1.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return helper(0, 0, n, s1, s2, dp);
    }
};