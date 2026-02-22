class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int posi = 0;
        int ans = 0;
        while (n) {
            int rem = n % 2;
            n /= 2;
            if (rem == 1) {
                if (prev != -1) {
                    ans = max(ans, posi - prev);
                }
                prev = posi;
            }
            posi++;
        }
        return ans;
    }
};