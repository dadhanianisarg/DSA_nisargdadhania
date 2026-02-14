class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        dp[0][0] = poured;
        for (int r = 1; r <= query_row; r++) {
            for (int c = 0; c <= r; c++) {
                double fromLeft = 0.0;
                double fromRight = 0.0;
                if (c - 1 >= 0) {
                    fromLeft = max(0.0, (dp[r - 1][c - 1] - 1.0) / 2.0);
                }

                if (c <= r - 1) {
                    fromRight = max(0.0, (dp[r - 1][c] - 1.0) / 2.0);
                }
                dp[r][c] = fromLeft + fromRight;
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};

// class Solution {
// public:
//     double helper(int r, int c, int poured, vector<vector<double>>& dp) {
//         if (c < 0 || c > r) return 0.0;
//         if (r == 0 && c == 0)
//             return poured;

//         if (dp[r][c] != -1.0)
//             return dp[r][c];

//         double left = helper(r - 1, c - 1, poured, dp);
//         double right = helper(r - 1, c, poured, dp);

//         double fromLeft = max(0.0, (left - 1.0) / 2.0);
//         double fromRight = max(0.0, (right - 1.0) / 2.0);
//         dp[r][c] = fromLeft + fromRight;
//         return dp[r][c];
//     }

//     double champagneTower(int poured, int query_row, int query_glass) {
//         vector<vector<double>> dp(101, vector<double>(101, -1.0));
//         double ans = helper(query_row, query_glass, poured, dp);
//         return min((double)1, ans);
//     }
// };
