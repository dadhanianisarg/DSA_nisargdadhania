class Solution {
    int getEnd(string& s, unordered_map<char, vector<int>>& mp, int st) {
        int end = mp[s[st]][1];

        for (int i = st; i <= end; i++) {
            if (mp[s[i]][0] < st)
                return -1;
            end = max(end, mp[s[i]][1]);
        }
        return end;
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, vector<int>> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]][1] = i;
            } else {
                mp[s[i]] = {i, i};
            }
        }

        vector<string> ans;
        int lastEnd = -1;

        for (int i = 0; i < n; i++) {
            if (mp[s[i]][0] == i) {
                int end = getEnd(s, mp, i);
                if (end != -1) {
                    if (i > lastEnd) {
                        ans.push_back("");
                    }
                    lastEnd = end;
                    ans.back() = s.substr(i, end - i + 1);
                }
            }
        }

        return ans;
    }
};
