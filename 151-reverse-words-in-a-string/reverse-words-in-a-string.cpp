class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int st = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + st, s.begin() + i);
                st = i + 1;
            }
        }
        if (s[s.size() - 1] != 32)
            reverse(s.begin() + st, s.begin() + s.size());
        int i = 0;
        while (i < s.size() && s[i] == 32) {
            s.erase(i, 1);
            // i++;
        }
        i = s.size() - 1;
        while (i >= 0 && s[i] == 32) {
            s.erase(i, 1);
            i--;
        }

        i = 0;
        while (i < s.size()) {
            if (i + 1 < s.size() && s[i] == 32 && s[i + 1] == 32) {
                s.erase(i, 1);
                continue;
            }
            i++;
        }
        return s;
    }
};