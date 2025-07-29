class Solution {
private:
    // 1) Pure recursion (exponential time)
    // Time: O(3^(n*m)) in worst-case
    // Space: O(n) recursion stack depth
    int recursiveDFS(int r, int c, int n, int m, vector<vector<int>>& A) {
        // horizontal bounds check: if out-of-bounds return large positive
        if (c < 0 || c >= m) return INT_MAX / 2;
        // if reached last row, path ends here
        if (r == n - 1) return A[r][c];
        // try moving down, down-left, down-right and take minimum
        int down      = A[r][c] + recursiveDFS(r + 1, c,   n, m, A);
        int downLeft  = A[r][c] + recursiveDFS(r + 1, c - 1, n, m, A);
        int downRight = A[r][c] + recursiveDFS(r + 1, c + 1, n, m, A);
        // pick the minimum of three options
        return min({down, downLeft, downRight});
    }

    // 2) Memoization (top-down DP)
    // Time: O(n*m) since each cell computed once
    // Space: O(n*m) for dp + O(n) recursion stack
    int dfsMemo(int r, int c, int n, int m,
                vector<vector<int>>& A,
                vector<vector<int>>& dp) {
        // bounds check horizontally
        if (c < 0 || c >= m) return INT_MAX / 2;
        // if at last row, return value
        if (r == n - 1) return A[r][c];
        // if already computed, return memo
        if (dp[r][c] != INT_MAX) return dp[r][c];
        // compute subpaths and take minimum
        int down      = A[r][c] + dfsMemo(r + 1, c,   n, m, A, dp);
        int downLeft  = A[r][c] + dfsMemo(r + 1, c - 1, n, m, A, dp);
        int downRight = A[r][c] + dfsMemo(r + 1, c + 1, n, m, A, dp);
        // store and return the best (minimum)
        return dp[r][c] = min({down, downLeft, downRight});
    }

    // 3) Tabulation (bottom-up DP)
    // Time: O(n*m) two nested loops
    // Space: O(n*m) dp array
    int tabulation(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        // dp[i][j]: min path sum from top to (i,j)
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        // initialize first row: starting points
        for (int j = 0; j < m; ++j)
            dp[0][j] = A[0][j];
        // fill dp row by row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int best = dp[i-1][j];           // from directly above
                if (j > 0)       best = min(best, dp[i-1][j-1]); // above-left
                if (j + 1 < m)   best = min(best, dp[i-1][j+1]); // above-right
                dp[i][j] = A[i][j] + best;        // add current cell value
            }
        }
        // answer is min in the last row
        int ans = INT_MAX;
        for (int j = 0; j < m; ++j)
            ans = min(ans, dp[n-1][j]);
        return ans;
    }

    // 4) Space-optimized DP
    // Time: O(n*m), Space: O(m) two rolling arrays
    int spaceOptimization(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        // prev holds dp values for previous row
        vector<int> prev(m);
        // initialize with first row
        for (int j = 0; j < m; ++j)
            prev[j] = A[0][j];
        // iterate rows
        for (int i = 1; i < n; ++i) {
            vector<int> curr(m);
            for (int j = 0; j < m; ++j) {
                int best = prev[j];                   // above
                if (j > 0)       best = min(best, prev[j-1]); // above-left
                if (j + 1 < m)   best = min(best, prev[j+1]); // above-right
                curr[j] = A[i][j] + best;            // include current cell
            }
            prev = move(curr); // roll curr into prev for next iteration
        }
        // answer is min in prev (last row)
        int ans = INT_MAX;
        for (int j = 0; j < m; ++j)
            ans = min(ans, prev[j]);
        return ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // 1) Pure recursion:
        // int res = INT_MAX;
        // for (int j = 0; j < m; ++j)
        //     res = min(res, recursiveDFS(0, j, n, m, matrix));
        // return res;

        // 2) Memoization:
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int res = INT_MAX;
        for (int j = 0; j < m; ++j)
            res = min(res, dfsMemo(0, j, n, m, matrix, dp));
        return res;

        // 3) Tabulation:
        // return tabulation(matrix);

        // 4) Space Optimization:
        // return spaceOptimization(matrix);
    }
};
