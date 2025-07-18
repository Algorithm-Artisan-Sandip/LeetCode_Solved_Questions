class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid, int dRow[], int dCol[]) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            // Explore 4 directions
            for(int i = 0; i < 4; i++) {
                int newRow = currRow + dRow[i];
                int newCol = currCol + dCol[i];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                   && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        // Step 1: Perform BFS from all boundary land cells
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !vis[0][j]) {
                bfs(0, j, vis, grid, dRow, dCol);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]) {
                bfs(n-1, j, vis, grid, dRow, dCol);
            }
        }
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) {
                bfs(i, 0, vis, grid, dRow, dCol);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]) {
                bfs(i, m-1, vis, grid, dRow, dCol);
            }
        }
        // Step 2: Count unvisited land cells (enclaves)
        int enclaves = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    enclaves++;
                }
            }
        }
        return enclaves;
    }
};
