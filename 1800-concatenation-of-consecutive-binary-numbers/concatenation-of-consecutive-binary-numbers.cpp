class Solution {
    const int MOD = 1e9 + 7;
    
    int helper(int n) {
        if (n == 0)
            return 0;

        int prev = helper(n - 1);
        int bits = log2(n) + 1;
        long long ans = ((long long)prev << bits) % MOD;
        ans = (ans + n) % MOD;

        return ans;
    }

public:
    int concatenatedBinary(int n) { return helper(n); }
};