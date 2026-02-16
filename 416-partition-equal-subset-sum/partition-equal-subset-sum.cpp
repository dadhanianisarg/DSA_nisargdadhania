class Solution {
    bool helper(int i, int sum, int& totSum, vector<int>& nums,
                vector<vector<int>>& dp) {
        if (sum * 2 == totSum)
            return true;
        if (i == nums.size()) {
            return sum * 2 == totSum;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = helper(i + 1, sum + nums[i], totSum, nums, dp);
        bool notTake = helper(i + 1, sum, totSum, nums, dp);
        return dp[i][sum] = take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for (auto& i : nums)
            totSum += i;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(totSum, -1));
        return helper(0, 0, totSum, nums, dp);
    }
};