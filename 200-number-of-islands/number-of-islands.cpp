// Approach 2 : 
class Solution {
private:
    void bfs(int i, int j, int n, int m, vector<vector<char>>& grid,  vector<vector<bool>>& visited) {
      queue<pair<int,int>> q;
      visited[i][j] = true;
      q.push({i, j});

      int row[] = {-1, 0, +1, 0};
      int col[] = {0, +1, 0, -1};

      while(!q.empty()) {
        auto frontNode = q.front();
        q.pop();
        int r = frontNode.first;
        int c = frontNode.second;

        for(int k=0; k<4; k++) {
            int newRow = r + row[k];
            int newCol = c + col[k];

            if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] == '1') {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
      }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();

       vector<vector<bool>> visited(n, vector<bool>(m, false));

       int islandCnt = 0;
       for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && grid[i][j] == '1') {
                islandCnt++;
                bfs(i, j, n, m, grid, visited);
            }
        }
       } 

       return islandCnt;
    }
};


// // Approach 1 : 
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty() || grid[0].empty()) {
//             return 0;
//         }
        
//         int numIslands = 0;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 if (grid[i][j] == '1') {
//                     numIslands++;
//                     dfs(grid, i, j);
//                 }
//             }
//         }
        
//         return numIslands;
//     }
    
// private:
//     void dfs(vector<vector<char>>& grid, int i, int j) {
//         if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
//             return;
//         }
        
//         grid[i][j] = '0'; // mark as visited
//         dfs(grid, i + 1, j); // down
//         dfs(grid, i - 1, j); // up
//         dfs(grid, i, j + 1); // right
//         dfs(grid, i, j - 1); // left
//     }
// };