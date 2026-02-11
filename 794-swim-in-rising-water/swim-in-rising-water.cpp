// class Solution {
// public:
//     int swimInWater(vector<vector<int>>& grid) {

//     }
// };

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == n - 1 && y == n - 1)
                return time;

            for (int i = 0; i < 4; i++) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1;
    }
};