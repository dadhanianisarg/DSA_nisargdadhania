class Solution {
    int helper(int i, int prevInd, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (i == nums.size())
            return 0;

        if (dp[i][prevInd + 1] != -1)
            return dp[i][prevInd + 1];
        int take = 0;
        if (prevInd == -1 || nums[i] > nums[prevInd])
            take = 1 + helper(i + 1, i, nums, dp);
        int notTake = helper(i + 1, prevInd, nums, dp);
        return dp[i][prevInd + 1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, nums, dp);
    }
};