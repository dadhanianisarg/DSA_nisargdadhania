class Solution {
    int solveTwoChars(string& s, char x, char y) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int cntX = 0, cntY = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == x) {
                cntX++;
            } else if (s[i] == y) {
                cntY++;
            } else {
                mp.clear();
                cntX = 0;
                cntY = 0;
                mp[0] = i;
                continue;
            }

            int diff = cntX - cntY;

            if (mp.find(diff) != mp.end()) {
                maxLen = max(maxLen, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }

        return maxLen;
    }

    int solveThreeChars(string& s) {
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;

        int cntA = 0, cntB = 0, cntC = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a')
                cntA++;
            else if (s[i] == 'b')
                cntB++;
            else
                cntC++;
            pair<int, int> key = {cntB - cntA, cntC - cntA};
            if (mp.find(key) != mp.end()) {
                maxLen = max(maxLen, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return maxLen;
    }

public:
    int longestBalanced(string s) {
        int ans = 1;
        int n = s.size();
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == c)
                cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
                c = s[i];
            }
        }
        ans = max(ans, cnt);

        ans = max(ans, solveTwoChars(s, 'a', 'b'));
        ans = max(ans, solveTwoChars(s, 'b', 'c'));
        ans = max(ans, solveTwoChars(s, 'a', 'c'));

        ans = max(ans, solveThreeChars(s));

        return ans;
    }
};