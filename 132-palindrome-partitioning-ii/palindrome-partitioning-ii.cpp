class Solution {
    bool isValid(string& s) {
        int l = 0;
        int r = s.size() - 1;
        while (r > l) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    int helper(int ind, string& s, vector<int>& dp) {
        if (ind == s.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        string temp = "";
        int ans = INT_MAX;
        for (int i = ind; i < s.size(); i++) {
            temp += s[i];
            int cnt = 0;
            if (isValid(temp)) {
                cnt += 1 + helper(i + 1, s, dp);
                ans = min(ans, cnt);
            }
        }
        return dp[ind] = ans;
    }

public:
    int minCut(string s) {
        vector<int> dp(s.size() + 1, -1);
        return helper(0, s, dp) - 1;
    }
};

// even after memo in this logic gives TLE
// class Solution {
//     unordered_map<string, int> dp;
//     bool isValid(const string& s) {
//         int l = 0;
//         int r = s.size() - 1;
//         while (l < r) {
//             if (s[l++] != s[r--])
//                 return false;
//         }
//         return true;
//     }

//     int helper(string& s) {
//         if (s.size() == 0 || isValid(s))
//             return 0;
//         if (dp.count(s))
//             return dp[s];

//         int ans = INT_MAX;
//         for (int i = 0; i < s.size(); i++) {
//             string leftString = s.substr(0, i + 1);
//             string rightString = s.substr(i + 1);
//             if (isValid(leftString)) {
//                 int cnt = 1 + helper(rightString);
//                 ans = min(ans, cnt);
//             }
//         }
//         return dp[s] = ans;
//     }

// public:
//     int minCut(string s) { return helper(s); }
// };