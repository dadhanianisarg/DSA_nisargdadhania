class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            dp[i][m - 1] = matrix[i][m - 1];
        for (int j = 0; j < m; j++)
            dp[n - 1][j] = matrix[n - 1][j];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (matrix[i][j])
                    dp[i][j] =
                        1 + min({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]});
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

// class Solution {
//     int helper(int i, int j, vector<vector<int>>& matrix,
//                vector<vector<int>>& dp) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         if (i >= n || j >= m)
//             return 0;
//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int right = helper(i, j + 1, matrix, dp);
//         int down = helper(i + 1, j, matrix, dp);
//         int diag = helper(i + 1, j + 1, matrix, dp);

//         if (matrix[i][j] == 1)
//             dp[i][j] = 1 + min({right, down, diag});
//         else
//             dp[i][j] = 0;

//         return dp[i][j];
//     }

// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 ans += helper(i, j, matrix, dp);
//             }
//         }
//         return ans;
//     }
// };