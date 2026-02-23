class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<vector<bool>> pick(n + 1, vector<bool>(n + 1, false));

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int notTake = dp[prev + 1][curr + 1];
                int take = 0;
                if (prev == -1 || nums[curr] % nums[prev] == 0) {
                    take = 1 + dp[curr + 1][curr + 1];
                }
                if (take > notTake) {
                    dp[prev + 1][curr] = take;
                    pick[prev + 1][curr] = true;
                } else {
                    dp[prev + 1][curr] = notTake;
                }
            }
        }
        vector<int> ans;
        int prev = -1, curr = 0;

        while (curr < n) {
            if (pick[prev + 1][curr]) {
                ans.push_back(nums[curr]);
                prev = curr;
            }
            curr++;
        }

        return ans;
    }
};

// class Solution {
// public:
//     int solve(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp,
//               vector<vector<bool>>& pick) {
//         if (curr == nums.size())
//             return 0;
//         if (dp[prev + 1][curr] != -1)
//             return dp[prev + 1][curr];
//         int notTake = solve(prev, curr + 1, nums, dp, pick);

//         int take = 0;
//         if (prev == -1 || nums[curr] % nums[prev] == 0) {
//             take = 1 + solve(curr, curr + 1, nums, dp, pick);
//         }

//         if (take > notTake) {
//             pick[prev + 1][curr] = true;
//             return dp[prev + 1][curr] = take;
//         }

//         return dp[prev + 1][curr] = notTake;
//     }

//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         vector<vector<int>> dp(n + 1, vector<int>(n, -1));
//         vector<vector<bool>> pick(n + 1, vector<bool>(n, false));
//         solve(-1, 0, nums, dp, pick);
//         vector<int> ans;
//         int prev = -1, curr = 0;

//         while (curr < n) {
//             if (pick[prev + 1][curr]) {
//                 ans.push_back(nums[curr]);
//                 prev = curr;
//             }
//             curr++;
//         }

//         return ans;
//     }
// };