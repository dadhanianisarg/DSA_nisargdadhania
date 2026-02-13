class Solution {
    int dayFinder(int i, vector<int>& days, int d) {
        int x = days[i] + d - 1;
        int l = i;
        int r = days.size();                              
        while (l < r) {
            int m = l + (r - l) / 2;
            if (days[m] <= x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    int helper(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i == days.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int day1 = costs[0] + helper(i + 1, days, costs, dp);

        int i7 = dayFinder(i, days, 7);
        int day7 = costs[1] + helper(i7, days, costs, dp);
        
        int i30 = dayFinder(i, days, 30);
        int day30 = costs[2] + helper(i30, days, costs, dp);
        return dp[i] = min({day1, day7, day30});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return helper(0, days, costs, dp);
    }
};