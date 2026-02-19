class Solution {
    string text1;
    string text2;
    int n1, n2;
    vector<vector<int>> dp;

    int longestCommonSubsequence() {
        for (int i1 = n1 - 1; i1 >= 0; i1--) {
            for (int i2 = n2 - 1; i2 >= 0; i2--) {
                int match = 0;

                if (text1[i1] == text2[i2])
                    match = 1 + dp[i1 + 1][i2 + 1];

                int notMatch1 = dp[i1 + 1][i2];
                int notMatch2 = dp[i1][i2 + 1];

                dp[i1][i2] = max({match, notMatch1, notMatch2});
            }
        }
        return dp[0][0];
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        text1 = str1;
        text2 = str2;
        n1 = text1.size();
        n2 = text2.size();
        dp.assign(n1 + 1, vector<int>(n2 + 1, 0));

        int maxComLen = longestCommonSubsequence();
        string lcs = "";
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (text1[i] == text2[j]) {
                lcs += text1[i];
                i++;
                j++;
            } else if (dp[i + 1][j] >= dp[i][j + 1]) {
                i++;
            } else {
                j++;
            }
        }

        string scs = "";
        i = 0, j = 0;
        for (char c : lcs) {
            while (str1[i] != c) {
                scs += str1[i++];
            }
            while (str2[j] != c) {
                scs += str2[j++];
            }
            scs += c;
            i++;
            j++;
        }
        while (i < n1)
            scs += str1[i++];
        while (j < n2)
            scs += str2[j++];
        return scs;
    }
};
