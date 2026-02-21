class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int R = floor(log2(right)) + 1;
        vector<bool> isPrime(R + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= R; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= R; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int ans = 0;
        for (int i = left; i <= right; i++) {
            int no = i;
            int cnt = 0;
            while (no) {
                cnt += no & 1;
                no >>= 1;
            }
            if (isPrime[cnt])
                ans++;
        }
        return ans;
    }
};