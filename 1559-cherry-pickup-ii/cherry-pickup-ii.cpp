class Solution {
private:
    // Pure recursion (exponential time)
    int recursive(int row, int c1, int c2, const vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // If either robot goes out of grid bounds horizontally, return large negative value (invalid path)
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return INT_MIN / 2;
        // Cherries collected at current row, if same position don't double count
        int cherries = (c1 == c2)
            ? grid[row][c1]
            : grid[row][c1] + grid[row][c2];
        // Base case: last row, just return cherries collected here
        if (row == n - 1)
            return cherries;

        int d[3] = {-1, 0, +1}; // possible moves: left, stay, or right
        int best = INT_MIN / 2;
        // Try all possible moves for both robots in next row (3 x 3 = 9 combinations)
        for (int dx1 : d) {
            for (int dx2 : d) {
                best = max(best,
                    recursive(row + 1, c1 + dx1, c2 + dx2, grid));
            }
        }
        // Add cherries collected this step to best collected in future steps
        return cherries + best;
    }

    // Top‑down memoization (O(n·m²) time & space)
    int memorization(int row, int c1, int c2, const vector<vector<int>>& grid,
                     vector<vector<vector<int>>>& dp) {
        int n = grid.size(), m = grid[0].size();
        // Return large negative if either robot walks off grid
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return INT_MIN / 2;
        // Cherries at this step, count only once if both robots share cell
        int cherries = (c1 == c2) ? grid[row][c1] : grid[row][c1] + grid[row][c2];
        // When at bottom row, return
        if (row == n - 1)
            return cherries;

        // If already computed this state, just return cached value
        if (dp[row][c1][c2] != -1)
            return dp[row][c1][c2];

        int d[3] = {-1, 0, +1};
        int best = INT_MIN / 2;
        // Try all 9 move options for both robots for next step
        for (int dx1 : d) {
            for (int dx2 : d) {
                best = max(best,
                    memorization(row + 1, c1 + dx1, c2 + dx2, grid, dp));
            }
        }
        // Memoize and return the result
        return dp[row][c1][c2] = cherries + best;
    }
    
    // Tabulation (bottom-up DP)
    int tabulation(int row, int c1, int c2, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // 3D DP array: dp[row][col1][col2] stores max cherries from row,col1,col2 to bottom
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(m, -1)));
        // Initialize DP for the last row (base case)
        for(int j1=0; j1<grid[0].size(); j1++) {
            for(int j2=0; j2<grid[0].size(); j2++) {
                if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1]; // both robots at same cell
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2]; // separate cells
            }
        }
        
        int dCol[] = {-1, 0, +1}; // possible moves
        // Bottom-up computation from 2nd last row to first
        for(int i=n-2; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    int maxi = 0; // max cherries for current configuration
                    // Loop over all next move combinations (3x3)
                    for(int dj1=-1; dj1<=1; dj1++) {
                        for(int dj2=-1; dj2<=1; dj2++) {
                            int value = 0;
                            // Cherries at this cell(s)
                            if(j1==j2) value += grid[i][j1];
                            else value += grid[i][j1] + grid[i][j2];
                            // Check if move is valid (inside bounds)
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) 
                                value += dp[i+1][j1+dj1][j2+dj2];
                            maxi = max(maxi, value); // best among all options
                        }
                    }
                    dp[i][j1][j2] = maxi; // fill current state
                }
            }
        }
        // Answer is the maximum cherries starting at (0,0) and (0,m-1)
        return dp[0][0][m-1];
    }
    
    // Space optimized tabulation (use two 2D arrays instead of 3D)
    int spaceOptimization(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // Only need DP for current and next step (front/curr)
        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));
        // Initialize for bottom row
        for(int j1=0; j1<grid[0].size(); j1++) {
            for(int j2=0; j2<grid[0].size(); j2++) {
                if(j1==j2) front[j1][j2] = grid[n-1][j1];
                else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        int dCol[] = {-1, 0, +1};
        // Iterate from 2nd last row up to top
        for(int i=n-2; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    int maxi = 0;
                    // Try all move combos for both robots
                    for(int dj1=-1; dj1<=1; dj1++) {
                        for(int dj2=-1; dj2<=1; dj2++) {
                            int value = 0;
                            // Add cherries at current cells
                            if(j1==j2) value += grid[i][j1];
                            else value += grid[i][j1] + grid[i][j2];
                            // If valid moves, add future value, else a large negative
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) 
                                value += front[j1+dj1][j2+dj2];
                            else 
                                value += -1e9;
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            // Move curr DP array to front for next iteration (swap roles)
            front = curr;
        }
        // Result for both robots starting at top-left and top-right corner
        return front[0][m-1];
    }

public:
    // Unified function to select which approach to use
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // Uncomment to use pure recursion (may TLE for large n,m)
        // return recursive(0, 0, m - 1, grid);

        // Top‑down memoization
        // vector<vector<vector<int>>> dp(n,
        //     vector<vector<int>>(m, vector<int>(m, -1)));
        // return memorization(0, 0, m - 1, grid, dp);
        
        // Bottom-up tabulation approach
        // return tabulation(0, 0, m-1, grid);
        
        // Space optimized bottom-up DP
        return spaceOptimization(grid);
    }
};
