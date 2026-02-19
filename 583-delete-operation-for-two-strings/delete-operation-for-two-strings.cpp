class Solution {
    int helper(int i, int j, string& word1, string& word2,
               vector<vector<int>>& dp) {
        int n1 = word1.size();
        int n2 = word2.size();
        if (i == n1)
            return n2 - j;
        if (j == n2)
            return n1 - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j]) {
            return helper(i + 1, j + 1, word1, word2, dp);
        }
        int delFromW1 = helper(i + 1, j, word1, word2, dp);
        int delFromW2 = helper(i, j + 1, word1, word2, dp);

        return dp[i][j] = 1 + min(delFromW1, delFromW2);
    }

public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return helper(0, 0, word1, word2, dp);
    }
};

// using concept of LCS
// class Solution {
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
//         vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
//         for (int i1 = n1 - 1; i1 >= 0; i1--) {
//             for (int i2 = n2 - 1; i2 >= 0; i2--) {
//                 int match = 0;
//                 if (text1[i1] == text2[i2])
//                     match = 1 + dp[i1 + 1][i2 + 1];
//                 int notMatch1 = dp[i1 + 1][i2];
//                 int notMatch2 = dp[i1][i2 + 1];
//                 dp[i1][i2] = max({match, notMatch1, notMatch2});
//             }
//         }
//         return dp[0][0];
//     }

// public:
//     int minDistance(string word1, string word2) {
//         int maxCommonLen = longestCommonSubsequence(word1, word2);
//         return word1.size() - maxCommonLen + word2.size() - maxCommonLen;
//     }
// };