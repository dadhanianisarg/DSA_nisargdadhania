class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ans = true;
        int prev = n % 2;
        n /= 2;
        while (n) {
            int curr = n % 2;
            n /= 2;
            if (prev == curr)
                return false;
            prev = curr;
        }
        return ans;
    }
};