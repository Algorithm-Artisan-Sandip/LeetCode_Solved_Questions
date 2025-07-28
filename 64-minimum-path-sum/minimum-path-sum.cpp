class Solution {
private:
    // Pure Recursive Solution : T.C: O(2^n), S.C: O(n) : 
    void recursive(int n, int m, vector<vector<int>>& grid, 
                  int &finalAns, int currAns) {
        if(currAns > finalAns) return;
        if(n==0 && m==0) {
            finalAns = min(finalAns, currAns+grid[0][0]);
            return;
        }
        if(n<0 || m<0) return;
        recursive(n-1, m, grid, finalAns, currAns+grid[n][m]);
        recursive(n, m-1, grid, finalAns, currAns+grid[n][m]);
        return;
    }

    // Brute DP : Memorization : 
    int memorization(int n, int m, vector<vector<int>>& grid, 
                     vector<vector<int>>& dp) {
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return INT_MAX;
        if(dp[n][m] != -1) return dp[n][m];
        int up = memorization(n-1, m, grid, dp);
        int left = memorization(n, m-1, grid, dp);
        return dp[n][m] = grid[n][m] + min(up, left);
    }

    // Better DP : Tabulation : 
    int tabulation(int n, int m, vector<vector<int>>& grid) {
        if(n==0 && m==0) return grid[0][0];
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = grid[0][0];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                if(i==0 && j==0) continue;
                int down = (i>0) ? dp[i-1][j] : INT_MAX;
                int right = (j>0) ? dp[i][j-1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(down, right);
            }
        }
        return dp[n][m];
    }


public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size()-1, m = grid[0].size()-1;
        int ans = INT_MAX;

        // recursive(n, m, grid, ans, 0);

        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // ans = memorization(n, m, grid, dp);

        ans = tabulation(n, m, grid);
        return ans;
    }
};