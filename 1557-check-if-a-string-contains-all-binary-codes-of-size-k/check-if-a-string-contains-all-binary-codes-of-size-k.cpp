class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        if (k >= s.size())
            return false;
        string binCode = s.substr(0, k);
        st.insert(binCode);
        int r = k;
        while (r < s.size()) {
            binCode.erase(binCode.begin());
            binCode += s[r];
            st.insert(binCode);
            r++;
        }
        if (st.size() == pow(2, k))
            return true;
        return false;
    }
};