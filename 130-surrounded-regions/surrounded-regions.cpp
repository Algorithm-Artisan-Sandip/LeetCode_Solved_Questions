class Solution {
  private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        // Direction vectors: up, right, down, left
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        int n = mat.size();
        int m = mat[0].size();
        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newRow = currRow + dRow[i];
                int newCol = currCol + dCol[i];
                // Check bounds and if it's an unvisited 'O'
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                   mat[newRow][newCol] == 'O' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // Visited matrix to keep track of 'O's connected to borders
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // Step 1: Traverse border cells and start BFS from 'O's
        // Traversing border rows : 
        for(int j = 0; j < m; j++) {
            // first row :
            if(mat[0][j] == 'O' && !vis[0][j]) {
                bfs(0, j, vis, mat);
            }
            // last row :
            if(mat[n-1][j] == 'O' && !vis[n-1][j]) {
                bfs(n-1, j, vis, mat);
            }
        }
        // Traversing border cols : 
        for(int i=0; i<n; i++) {           
            // first col : 
            if(mat[i][0] == 'O' && !vis[i][0]) {
                bfs(i, 0, vis, mat);
            }
            // last col : 
            if(mat[i][m-1] == 'O' && !vis[i][m-1]) {
                bfs(i, m-1, vis, mat);
            }
        }
        // Step 2: Convert unvisited 'O's to 'X' (they are surrounded)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O' && !vis[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }        
    }
};