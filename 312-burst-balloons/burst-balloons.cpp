class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<unsigned long long>> dp(n + 2, vector<unsigned long long>(n + 2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j < n + 1; j++) {
                unsigned long long ans = 0;
                for (int ind = i; ind <= j; ind++) {
                    unsigned long long coins = nums[i - 1] * nums[ind] * nums[j + 1] +
                                      dp[i][ind - 1] + dp[ind + 1][j];
                    ans = max(ans, coins);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};

// class Solution {
//     int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
//         if (i > j)
//             return 0;
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         int ans = 0;
//         for (int ind = i; ind <= j; ind++) {
//             int coins = nums[i - 1] * nums[ind] * nums[j + 1] +
//                         helper(i, ind - 1, nums, dp) +
//                         helper(ind + 1, j, nums, dp);
//             ans = max(ans, coins);
//         }
//         return dp[i][j] = ans;
//     }

// public:
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();
//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);
//         vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
//         return helper(1, n, nums, dp);
//     }
// };

// below memoization also cannot pass the testcase
// class Solution {
//     unordered_map<string, int> dp;
//     string makeKey(const vector<int>& nums) {
//         string key;
//         for (int x : nums) {
//             key += to_string(x) + ",";
//         }
//         return key;
//     }

//     int helper(vector<int> nums) {
//         if (nums.size() == 0)
//             return 0;
//         string key = makeKey(nums);
//         if (dp.count(key))
//             return dp[key];
//         int ans = 0;
//         for (int j = 0; j < (int)nums.size(); j++) {
//             int coins = nums[j];
//             if (j >= 1)
//                 coins *= nums[j - 1];
//             if (j < (int)nums.size() - 1)
//                 coins *= nums[j + 1];
//             int erasedEle = nums[j];
//             nums.erase(nums.begin() + j);
//             int temp = coins + helper(nums);
//             nums.insert(nums.begin() + j, erasedEle);
//             ans = max(ans, temp);
//         }
//         return dp[key] = ans;
//     }

// public:
//     int maxCoins(vector<int>& nums) {
//         dp.clear();
//         return helper(nums);
//     }
// };

// pure brute force
// class Solution {
//     int helper(vector<int> nums) {
//         if (nums.size() == 0)
//             return 0;
//         int ans = 0;
//         for (int j = 0; j < (int)nums.size(); j++) {
//             int coins = nums[j];
//             if (j >= 1)
//                 coins *= nums[j - 1];
//             if (j < nums.size() - 1)
//                 coins *= nums[j + 1];

//             int erasedEle = nums[j];
//             nums.erase(nums.begin() + j);
//             int temp = coins + helper(nums);
//             nums.insert(nums.begin() + j, erasedEle);
//             ans = max(ans, temp);
//         }
//         return ans;
//     }

// public:
//     int maxCoins(vector<int>& nums) { return helper(nums); }
// };