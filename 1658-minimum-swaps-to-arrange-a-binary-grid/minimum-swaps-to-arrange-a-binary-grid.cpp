class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> oneFromRight(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    oneFromRight[i] = j;
                    break;
                }
            }
        }

        vector<int> temp = oneFromRight;
        sort(temp.begin(), temp.end());

        for (int i = 0; i < n; i++) {
            if (temp[i] > i) {
                return -1;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int j = i;

            while (j < n && oneFromRight[j] > i) {
                j++;
            }

            while (j > i) {
                swap(oneFromRight[j], oneFromRight[j - 1]);
                ans++;
                j--;
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int minSwaps(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<int> freq(n, 0);

//         for (int i = 0; i < n; i++) {
//             int cnt0 = 0;
//             for (int j = n - 1; j >= 0; j--) {
//                 if (grid[i][j] == 1)
//                     break;
//                 cnt0++;
//             }
//             freq[cnt0]++;
//         }

//         int availa0 = 0;
//         for (int need = n - 1; need >= 0; need--) {
//             availa0 += freq[need];
//             if (availa0 == 0)
//                 return -1;
//             availa0--;
//         }

//     }
// };