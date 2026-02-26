class Solution {
    void divBy2(string& s) { s.erase(s.size() - 1); }

    void add1(string& s) {
        int n = s.size() - 1;
        while (n >= 0 && s[n] != '0') {
            s[n] = '0';
            n--;
        }
        if (n < 0)
            s = '1' + s;
        else
            s[n] = '1';
    }

public:
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        while (s.size() > 1) {
            n = s.size();
            if (s[n - 1] == '0')
                divBy2(s);
            else
                add1(s);
            ans++;
        }
        return ans;
    }
};

// this appraoch will definetly give you overflow as s.length is <= 500
// class Solution {
//     unsigned long long binToDeci(string& s) {
//         unsigned long long ans = 0;
//         for (int i = 0; i < s.size(); i++) {
//             ans = 2 * ans + (s[i] - '0');
//         }
//         return ans;
//     }

// public:
//     int numSteps(string s) {
//         unsigned long long deci = binToDeci(s);
//         int ans = 0;
//         while (deci != 1) {
//             if (deci % 2 == 0)
//                 deci /= 2;
//             else
//                 deci++;
//             ans++;
//         }
//         return ans;
//     }
// };