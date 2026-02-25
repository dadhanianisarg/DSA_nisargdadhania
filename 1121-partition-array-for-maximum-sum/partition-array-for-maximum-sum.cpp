class Solution {
    int helper(int ind, vector<int>& arr, int& k, vector<int>& dp) {
        if (ind == arr.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int ans = INT_MIN;
        int maxEle = arr[ind];
        for (int i = ind; i < min(ind + k, (int)arr.size()); i++) {
            int sum = 0;
            maxEle = max(maxEle, arr[i]);
            sum += maxEle * (i - ind + 1) + helper(i + 1, arr, k, dp);
            ans = max(ans, sum);
        }
        return dp[ind] = ans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1, -1);
        return helper(0, arr, k, dp);
    }
};