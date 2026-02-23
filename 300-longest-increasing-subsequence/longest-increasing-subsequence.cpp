class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back())
                temp.push_back(nums[i]);
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int i = n - 1; i >= 0; i--) {
//             for (int prevInd = 0; prevInd < n + 1; prevInd++) {

//                 int take = 0;
//                 if (prevInd == 0 || nums[i] > nums[prevInd - 1])
//                     take = 1 + dp[i + 1][i + 1];
//                 int notTake = dp[i + 1][prevInd];
//                 dp[i][prevInd] = max(take, notTake);
//             }
//         }

//         return dp[0][0];
//     }
// };

// class Solution {
//     int helper(int i, int prevInd, vector<int>& nums,
//                vector<vector<int>>& dp) {
//         if (i == nums.size())
//             return 0;

//         if (dp[i][prevInd + 1] != -1)
//             return dp[i][prevInd + 1];
//         int take = 0;
//         if (prevInd == -1 || nums[i] > nums[prevInd])
//             take = 1 + helper(i + 1, i, nums, dp);
//         int notTake = helper(i + 1, prevInd, nums, dp);
//         return dp[i][prevInd + 1] = max(take, notTake);
//     }

// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return helper(0, -1, nums, dp);
//     }
// };