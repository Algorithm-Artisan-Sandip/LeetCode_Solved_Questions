class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int sr = 0, sc = 0;
        int dr = n - 1, dc = n - 1;

        // 1) If start or end is blocked, no path exists
        if (grid[sr][sc] != 0 || grid[dr][dc] != 0) 
            return -1;

        // 2) If grid is 1x1 and it's clear, path length is 1
        if (sr == dr && sc == dc) 
            return 1;

        // 3) Direction vectors for 8 possible moves (including diagonals)
        int dRow[8] = {-1, -1, -1,  0, +1, +1, +1,  0};
        int dCol[8] = {-1,  0, +1, +1, +1,  0, -1, -1};

        // 4) Distance matrix initialized to "infinity"
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[sr][sc] = 0;

        // 5) BFS queue: stores {distance_so_far (edges), row, col}
        queue<tuple<int,int,int>> q;
        q.emplace(0, sr, sc);

        // 6) Standard BFS loop
        while (!q.empty()) {
            auto [currDist, r, c] = q.front();
            q.pop();

            // 7) Upon dequeuing destination, return #cells = #edges + 1
            if (r == dr && c == dc) 
                return currDist + 1;

            // 8) Explore all 8 neighbors
            for (int i = 0; i < 8; ++i) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];

                // 9) Check bounds, clear cell, and shorter path
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 &&
                    currDist + 1 < dist[nr][nc]) {
                    dist[nr][nc] = currDist + 1;
                    q.emplace(currDist + 1, nr, nc);
                }
            }
        }

        // 10) Destination never reached
        return -1;
    }
};
