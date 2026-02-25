class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> numBits;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            int cnt = 0;
            while (num) {
                int rem = num % 2;
                if (rem)
                    cnt++;
                num /= 2;
            }
            numBits.push_back({arr[i], cnt});
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < numBits.size(); i++) {
            int num = numBits[i].first;
            int bits = numBits[i].second;
            mp[bits].push_back(num);
        }
        vector<int> ans;
        for (auto& it : mp) {
            vector<int> temp = it.second;
            sort(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); i++) {
                ans.push_back(temp[i]);
            }
        }

        return ans;
    }
};