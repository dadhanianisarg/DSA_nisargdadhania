class Solution {
    int helper(int i, bool lastHouse, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (i == nums.size())
            return 0;

        if (dp[i][lastHouse] != -1)
            return dp[i][lastHouse];

        int rob = 0;
        if (!lastHouse)
            rob = nums[i] + helper(i + 1, true, nums, dp);

        int notRob = helper(i + 1, false, nums, dp);

        return dp[i][lastHouse] = max(rob, notRob);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, false, nums, dp);
    }
};
