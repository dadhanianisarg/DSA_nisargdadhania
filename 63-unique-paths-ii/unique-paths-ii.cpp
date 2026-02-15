class Solution {
    int helper(int i, int j, int m, int n, vector<vector<int>>& dp,
               vector<vector<int>>& obstacleGrid) {
        if (i >= m || j >= n)
            return 0;
        if (obstacleGrid[i][j] == 1)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = helper(i + 1, j, m, n, dp, obstacleGrid);
        int right = helper(i, j + 1, m, n, dp, obstacleGrid);
        return dp[i][j] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, m, n, dp, obstacleGrid);
    }
};
