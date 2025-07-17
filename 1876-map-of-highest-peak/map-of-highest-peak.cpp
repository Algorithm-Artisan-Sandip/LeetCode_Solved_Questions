class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();       // number of rows
        int m = isWater[0].size();    // number of columns
        // vis[r][c] == 1 means cell (r,c) has been visited/enqueued
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // dist[r][c] will store the final distance to nearest 1
        vector<vector<int>> dist(n, vector<int>(m, 0));
        // queue stores ((row, col), distance) for BFS
        queue<pair<pair<int, int>, int>> q;
        // Step 1: Enqueue all cells containing 1 as BFS sources
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    vis[i][j] = 1;           // mark source as visited
                    q.push({{i, j}, 0});     // distance = 0 for source cells
                }
            }
        }
        // Direction vectors for exploring 4 neighbors: up, right, down, left
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = { 0, 1, 0, -1};
        // Step 2: Perform multi-source BFS
        while(!q.empty()) {
            // Extract current cell and its distance
            auto front = q.front();
            int row = front.first.first;
            int col = front.first.second;
            int steps = front.second;
            q.pop();
            // Record the distance for this cell
            dist[row][col] = steps;
            // Explore all 4 adjacent neighbors
            for(int i = 0; i < 4; i++) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                // Check boundaries and if not yet visited
                if(newRow >= 0 && newRow < n && newCol >= 0 && 
                   newCol < m && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;  // mark neighbor visited
                    q.push({{newRow, newCol}, steps + 1}); // enqueue with distance +1
                }
            }
        }
        // Return the distance matrix
        return dist;        
    }
};