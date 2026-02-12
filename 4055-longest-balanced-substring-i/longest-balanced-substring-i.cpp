class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, -1);
            for (int j = i; j < n; j++) {
                if (freq[s[j] - 'a'] == -1) {
                    freq[s[j] - 'a'] = 1;
                } else
                    freq[s[j] - 'a']++;
                int maxFreq = -1;
                bool flag = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] != -1) {
                        if (maxFreq == -1)
                            maxFreq = freq[k];
                        else {
                            if (maxFreq != freq[k]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                if (flag)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};