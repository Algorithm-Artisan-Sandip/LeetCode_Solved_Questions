class Solution {
private:
    int bfsHelper(int n, int m, vector<vector<int>> grid, queue<pair<pair<int,int>, int>>& q, vector<vector<int>>& visited) {
        // building array to go up, right, down and left respectively
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};
        int maxTime = 0;

        while(!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            int r = frontNode.first.first;   // stores the row
            int c = frontNode.first.second;  // stores the col
            int t = frontNode.second;        // stores the time to be rottened
            maxTime = max(t, maxTime);       // each time maximizing the maxTime

            for(int i=0; i<4; i++) {         // as there are four neighbours possible up, right, down and left 
                int newRow = r + row[i];     
                int newCol = c + col[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && visited[newRow][newCol] == 0) {
                    grid[newRow][newCol] = 2;         // marking this orange as rotten
                    visited[newRow][newCol] = 1;      // marking this cell to be visited
                    q.push({{newRow, newCol}, t+1});  // pushing this rotten cells position and its rotting time
                }
            }
        }

        // checking if there is still any fresh orange remaining : 
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) return -1;    // if yes then return -1
            }
        }

        return maxTime;  // else return the maxTime
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();    // row size
        int m = grid[0].size(); // col size
        vector<vector<int>> visited(n, vector<int>(m,0));  // same dimensions as the the grid to track the visit to a particular cell
        queue<pair<pair<int,int>, int>> q;                 // stores row, col and time

        // initializing the queue and the visited array :
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {         // if the orange is rotten
                    visited[i][j] = 1;        // then mark it as visited
                    q.push({{i,j},0});        // also stores its position with rotting time as 0
                }
            }
        } 

        // call the bfs helper function : 
        int time = bfsHelper(n,m,grid,q,visited);
        return time;
    }
};