class Solution {
    string helper(string s) {
        vector<string> blocks;
        int cnt = 0, st = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt++;
            else
                cnt--;
            if (cnt == 0) {
                string inner = s.substr(st + 1, i - st - 1);
                blocks.push_back("1" + helper(inner) + "0");
                st = i + 1;
            }
        }

        sort(blocks.rbegin(), blocks.rend());

        string ans;
        for (auto& b : blocks)
            ans += b;

        return ans;
    }

public:
    string makeLargestSpecial(string s) { return helper(s); }
};