class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> grp;
        int curr = s[0];
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == curr)
                cnt++;
            else {
                grp.push_back(cnt);
                curr = s[i];
                cnt = 1;
            }
        }
        grp.push_back(cnt);
        int ans = 0;
        for (int i = 0; i < grp.size() - 1; i++) {
            ans += min(grp[i], grp[i + 1]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//         int l = 0;
//         int r = 0;
//         int n = s.size();
//         int cnt0 = 0;
//         int ans = 0;
//         while (r < n) {
//             if (s[r] == '0')
//                 cnt0++;
//             else
//                 cnt0--;
//             if (cnt0 == 0) {
//                 ans += (r - l + 1) / 2;
//                 l = r + 1;
//             }
//             r++;
//         }

//         int cnt1 = 0;
//         l = 0, r = 0;
//         while (r < n) {
//             if (s[r] == '1')
//                 cnt1++;
//             else if (cnt1 != 0)
//                 cnt1--;
//             if (cnt1 == 0) {
//                 ans += (r - l + 1) / 2;
//                 l = r + 1;
//             }
//             r++;
//         }
//         return ans;
//     }
// };