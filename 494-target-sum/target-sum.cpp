class Solution {
    int helper(int i, int sum, vector<int>& nums, int target,
               vector<vector<int>>& dp, int offset) {
        if (i == nums.size()) {
            return (sum == target) ? 1 : 0;
        }
        if (dp[i][sum + offset] != -1)
            return dp[i][sum + offset];
        int add = helper(i + 1, sum + nums[i], nums, target, dp, offset);
        int sub = helper(i + 1, sum - nums[i], nums, target, dp, offset);
        return dp[i][sum + offset] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));

        return helper(0, 0, nums, target, dp, totalSum);
    }
};
