class Solution {
    static bool compare(string& s, string& t) { return s.size() < t.size(); }

    bool checkPossible(string& s, string& t) {
        if (s.size() != t.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < s.size()) {
            if (j < t.size() && s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == t.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkPossible(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

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
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(), words.end(),
//              [](string& a, string& b) { return a.size() < b.size(); });
//         int n = words.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int curr = n - 1; curr >= 0; curr--) {
//             for (int prev = curr - 1; prev >= -1; prev--) {
//                 int notTake = dp[prev + 1][curr + 1];

//                 int take = 0;
//                 if (prev == -1) {
//                     take = 1 + dp[curr + 1][curr + 1];
//                 } else if (words[curr].size() == words[prev].size() + 1) {
//                     int len =
//                         longestCommonSubsequence(words[prev], words[curr]);
//                     if (len == words[curr].size() - 1) {
//                         take = 1 + dp[curr + 1][curr + 1];
//                     }
//                 }
//                 dp[prev + 1][curr] = max(take, notTake);
//             }
//         }
//         return dp[0][0];
//     }
// };

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
//     int helper(int prev, int curr, vector<string>& words,
//                vector<vector<int>>& dp) {

//         if (curr == words.size())
//             return 0;
//         if (dp[prev + 1][curr] != -1)
//             return dp[prev + 1][curr];

//         int notTake = helper(prev, curr + 1, words, dp);

//         int take = 0;
//         if (prev == -1) {
//             take = 1 + helper(curr, curr + 1, words, dp);
//         } else if (words[curr].size() == words[prev].size() + 1) {
//             int len = longestCommonSubsequence(words[prev], words[curr]);
//             if (len == words[curr].size() - 1) {
//                 take = 1 + helper(curr, curr + 1, words, dp);
//             }
//         }
//         return dp[prev + 1][curr] = max(take, notTake);
//     }

// public:
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(), words.end(),
//              [](string& a, string& b) { return a.size() < b.size(); });
//         int n = words.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
//         return helper(-1, 0, words, dp);
//     }
// };