class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        vector<vector<int>> cells;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());
        vector<vector<int>> active(n, vector<int>(n, 0));
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < cells.size(); i++) {
            int elev = cells[i][0];
            int r = cells[i][1];
            int c = cells[i][2];
            active[r][c] = 1;
            int node = r * n + c;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (active[nr][nc]) {
                        int adjNode = nr * n + nc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }

            if (ds.findUPar(0) == ds.findUPar(n * n - 1))
                return elev;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<vector<int>> vis(n, vector<int>(n, 0));
//         priority_queue<vector<int>, vector<vector<int>>,
//         greater<vector<int>>>
//             pq;
//         pq.push({grid[0][0], 0, 0});
//         vis[0][0] = 1;
//         int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//         while (!pq.empty()) {
//             auto curr = pq.top();
//             pq.pop();
//             int time = curr[0];
//             int x = curr[1];
//             int y = curr[2];

//             if (x == n - 1 && y == n - 1)
//                 return time;

//             for (int i = 0; i < 4; i++) {
//                 int nx = x + d[i][0];
//                 int ny = y + d[i][1];
//                 if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
//                     !vis[nx][ny]) {
//                     vis[nx][ny] = 1;
//                     pq.push({max(time, grid[nx][ny]), nx, ny});
//                 }
//             }
//         }
//         return -1;
//     }
// };