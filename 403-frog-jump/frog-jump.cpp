class Solution {
    int coordinateFinder(int target, vector<int>& stones) {
        for (int ind = 0; ind < stones.size(); ind++) {
            if (stones[ind] == target)
                return ind;
        }
        return -1;
    }

    bool helper(int i, int lastJump, vector<int>& stones,
                vector<vector<int>>& dp) {
        if (i == stones.size() - 1)
            return true;
        if (dp[i][lastJump] != -1)
            return dp[i][lastJump];
        int curr = stones[i];
        bool kminus1 = false, k = false, kplus1 = false;
        if (lastJump - 1 > 0) {
            int nextIndex = coordinateFinder(curr + lastJump - 1, stones);
            if (nextIndex != -1)
                kminus1 = helper(nextIndex, lastJump - 1, stones, dp);
        }

        int nextIndexK = coordinateFinder(curr + lastJump, stones);
        if (nextIndexK != -1)
            k = helper(nextIndexK, lastJump, stones, dp);

        int nextIndexKplus1 = coordinateFinder(curr + lastJump + 1, stones);
        if (nextIndexKplus1 != -1)
            kplus1 = helper(nextIndexKplus1, lastJump + 1, stones, dp);
        return dp[i][lastJump] = kminus1 || k || kplus1;
    }

public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(1, 1, stones, dp);
    }
};
