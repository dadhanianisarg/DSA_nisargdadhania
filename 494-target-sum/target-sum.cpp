class Solution {
    int helper(int i, int sum, vector<int>& nums, int& target) {
        if (i >= nums.size()) {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        int add = helper(i + 1, sum + nums[i], nums, target);
        int sub = helper(i + 1, sum - nums[i], nums, target);
        return add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0, 0, nums, target);
    }
};