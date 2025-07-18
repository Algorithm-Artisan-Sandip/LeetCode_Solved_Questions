class Solution {
  private:
  private:
    void dfs(int row, int col, vector<vector<int>>& vis, 
             vector<vector<char>>& mat, int dRow[], int dCol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            // Check bounds and if it's an unvisited 'O'
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
             && mat[newRow][newCol] == 'O' && !vis[newRow][newCol]) {
                dfs(newRow, newCol, vis, mat, dRow, dCol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // Direction vectors: up, right, down, left
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        // Visited matrix to keep track of 'O's connected to borders
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // Step 1: Traverse border cells and start BFS from 'O's
        // Traversing border rows : 
        for(int j = 0; j < m; j++) {
            // first row :
            if(mat[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, vis, mat, dRow, dCol);
            }
            // last row :
            if(mat[n-1][j] == 'O' && !vis[n-1][j]) {
                dfs(n-1, j, vis, mat, dRow, dCol);
            }
        }
        // Traversing border cols : 
        for(int i=0; i<n; i++) {           
            // first col : 
            if(mat[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, mat, dRow, dCol);
            }
            // last col : 
            if(mat[i][m-1] == 'O' && !vis[i][m-1]) {
                dfs(i, m-1, vis, mat, dRow, dCol);
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