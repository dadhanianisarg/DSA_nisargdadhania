// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<int> dp(triangle[n - 1]);
//         for (int i = n - 2; i >= 0; i--) {
//             for (int j = 0; j <= i; j++) {
//                 dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
//             }
//         }
//         return dp[0];
//     }
// };



// tabulation space complexity O(n^2);
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < triangle[n - 1].size(); j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];
                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }
        return dp[0][0];
    }
};




// memoization space complexity O(n^2) + stack space
// class Solution {
//     int helper(int row, int ind, vector<vector<int>>& triangle,
//                vector<vector<int>>& dp) {
//         if (row == triangle.size() - 1)
//             return triangle[row][ind];

//         if (dp[row][ind] != INT_MAX)
//             return dp[row][ind];
//         int down = helper(row + 1, ind, triangle, dp);
//         int diag = helper(row + 1, ind + 1, triangle, dp);
//         return dp[row][ind] = triangle[row][ind] + min(down, diag);
//     }

// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//         return helper(0, 0, triangle, dp);
//     }
// };
