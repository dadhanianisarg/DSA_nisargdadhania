class Solution {
    void checkValidTime(vector<int>& bits, vector<string>& ans) {
        int hrs = 0;
        for (int i = 0; i < 4; i++) {
            hrs += bits[i] * (1 << i);
        }
        if (hrs > 11)
            return;
        int min = 0;
        for (int i = 4; i < 10; i++) {
            min += bits[i] * (1 << (i - 4));
        }
        if (min > 59)
            return;
        string hrsS = to_string(hrs);
        string minS = (min < 10 ? "0" : "") + to_string(min);
        ans.push_back(hrsS + ":" + minS);
    }

    void helper(int i, int cnt, int turnedOn, vector<int>& bits,
                vector<string>& ans) {
        if (cnt == turnedOn) {
            checkValidTime(bits, ans);
            return;
        }
        if (i >= 10)
            return;
        bits[i] = 1;
        helper(i + 1, cnt + 1, turnedOn, bits, ans);
        bits[i] = 0;
        helper(i + 1, cnt, turnedOn, bits, ans);
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn > 8)
            return {};
        vector<string> ans;
        vector<int> bits(10, 0);
        helper(0, 0, turnedOn, bits, ans);
        return ans;
    }
};
