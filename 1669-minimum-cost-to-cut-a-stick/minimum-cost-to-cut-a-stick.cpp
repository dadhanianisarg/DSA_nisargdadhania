class Solution {
    int helper(int left, int right, vector<int>& cuts,
               vector<vector<int>>& dp) {
        if (right - left <= 1)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];
        int ans = INT_MAX;
        for (int i = left + 1; i < right; i++) {
            int lC = helper(left, i, cuts, dp);
            int rC = helper(i, right, cuts, dp);
            int totCost = (cuts[right] - cuts[left]) + lC + rC;
            ans = min(ans, totCost);
        }
        return dp[left][right] = ans;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return helper(0, m - 1, cuts, dp);
    }
};