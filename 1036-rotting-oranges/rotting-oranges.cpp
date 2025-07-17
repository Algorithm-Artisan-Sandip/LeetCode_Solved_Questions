class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();               // Number of rows
        int m = mat[0].size();            // Number of columns

        // Visited array to keep track of already processed cells
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int,int>> q;           // Queue to perform BFS
        int reqTime = 0;                  // Time required to rot all oranges
        int freshCnt = 0;                 // Count of fresh oranges
        int newRotten = 0;                // Count of fresh oranges that got rotten during BFS

        // Step 1: Count fresh oranges and enqueue all initially rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1)
                    freshCnt++;           // Count fresh orange
                else if(mat[i][j] == 2) {
                    vis[i][j] = 1;        // Mark as visited
                    q.push({i, j});       // Push initial rotten oranges to queue
                }
            }
        }

        // Directions for 4-connected neighbours (up, right, down, left)
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        // Step 2: BFS to rot adjacent fresh oranges level by level (minute by minute)
        while(!q.empty()) {
            int size = q.size(); 
            bool didRot = false;          // To check if any orange rotted in this round

            for (int i = 0; i < size; i++) {
                int currRow = q.front().first;
                int currCol = q.front().second;
                q.pop();

                // Check all 4 neighbours
                for(int k = 0; k < 4; k++) {
                    int newRow = currRow + dRow[k];
                    int newCol = currCol + dCol[k];

                    // If within bounds and unvisited fresh orange
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                       && !vis[newRow][newCol] && mat[newRow][newCol] == 1) {

                        vis[newRow][newCol] = 1;        // Mark it as visited
                        mat[newRow][newCol] = 2;        // Rot the orange
                        q.push({newRow, newCol});       // Add to queue for next round
                        newRotten++;                    // Count it
                        didRot = true;                  // Mark that we did rot at least one
                    }
                }
            }

            // If we rotted any orange in this level, increment time
            if(didRot)
                reqTime++;
        }

        // Step 3: If all fresh oranges got rotten, return time; else return -1
        return (freshCnt == newRotten) ? reqTime : -1;
    }
};
