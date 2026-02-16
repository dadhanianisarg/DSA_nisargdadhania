class Solution {
public:
    int reverseBits(int n) {

        int ans = 0;
        int i = 0;
        while (i < 32) {
            ans += (n % 2) * pow(2, 31 - i);
            i++;
            n /= 2;
        }
        return ans;
    }
};