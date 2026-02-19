class Solution {
    int helper(int i, int j, string& word1, string& word2,
               vector<vector<int>>& dp) {
        int n = word1.size();
        int m = word2.size();
        if (i >= n)
            return m - j;
        if (j >= m)
            return n - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j]) {
            return dp[i][j] = helper(i + 1, j + 1, word1, word2, dp);
        }
        int ins = helper(i, j + 1, word1, word2, dp);
        int del = helper(i + 1, j, word1, word2, dp);
        int rep = helper(i + 1, j + 1, word1, word2, dp);
        return dp[i][j] = 1 + min({ins, del, rep});
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, word1, word2, dp);
    }
};