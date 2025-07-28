class Solution {
private:
    // 1. Pure Recursive Solution (Exponential)
    // Main Idea:
    // - Try all paths by moving only right or down.
    // - Base case is when we reach (0,0), return 1.
    // - If out of bounds, return 0.
    // - Add paths coming from top and left.
    // Limitation:
    // - Very inefficient for large inputs due to repeated computations.
    // =============================================
    int recursive(int n, int m) {
        if (n == 0 && m == 0) return 1;        // Reached destination
        if (n < 0 || m < 0) return 0;          // Out of bounds
        int up = recursive(n - 1, m);    // Move from top
        int left = recursive(n, m - 1);  // Move from left
        return up + left;                      // Total ways to reach (n, m)
    }

    // =============================================
    // 2. Memoization (Top-Down DP)
    // Main Idea:
    // - Same as recursive, but cache results in a 2D dp table.
    // - Avoids recalculating overlapping subproblems.
    // - Use dp[n][m] to store number of ways to reach (n,m).
    // Benefit:
    // - Reduces time complexity to O(n*m)
    // =============================================
    int memoization(int n, int m, vector<vector<int>>& dp) {
        if (n == 0 && m == 0) return 1;
        if (n < 0 || m < 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];   // Reuse already computed result

        int up = memoization(n - 1, m, dp);    // Move from top
        int left = memoization(n, m - 1, dp);  // Move from left

        return dp[n][m] = up + left;           // Store and return result
    }

    // =============================================
    // 3. Tabulation (Bottom-Up DP)
    // Main Idea:
    // - Build the solution iteratively using a 2D dp table.
    // - dp[i][j] represents number of ways to reach cell (i,j).
    // - Start from (0,0) and fill row-wise or column-wise.
    // Benefit:
    // - Avoids recursion and gives better control on order.
    // =============================================
    int tabulation(int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;  // Only one way to start at (0,0)

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) continue; // Skip start cell
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;           // Sum of ways from top and left
            }
        }
        return dp[n][m];                        // Final destination value
    }

    // =============================================
    // 4. Space Optimized DP
    // Main Idea:
    // - Instead of keeping full 2D dp, keep only two 1D arrays:
    //   - `prev` to store results of previous row
    //   - `curr` to store results of current row
    // - For each cell, only previous row and left cell are required.
    // Benefit:
    // - Reduces space complexity from O(n*m) to O(m)
    // =============================================
    int spaceOptimized(int n, int m) {
        if (n == 0 && m == 0) return 1;

        vector<int> prev(m + 1, 0);            // Stores previous row
        for (int i = 0; i <= n; i++) {
            vector<int> curr(m + 1, 0);        // Stores current row
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0)
                    curr[0] = 1;               // Start position
                else {
                    int up = (i > 0) ? prev[j] : 0;     // Value from above
                    int left = (j > 0) ? curr[j - 1] : 0; // Value from left
                    curr[j] = up + left;
                }
            }
            prev = curr;                       // Move to next row
        }
        return prev[m];                        // Final destination value
    }

public:
    // Main function to be called with grid dimensions a x b
    // Each cell allows only moves: right or down
    int uniquePaths(int a, int b) {
        // Convert to 0-based indexing for internal computation
        int n = a - 1, m = b - 1;

        // 1. Pure Recursive (Not suitable for large input)
        // return recursive(n, m);

        // 2. Memoization
        vector<vector<int>> dp(a, vector<int>(b, -1));
        return memoization(n, m, dp);

        // 3. Tabulation
        // return tabulation(n, m);

        // 4. Space Optimized DP
        // return spaceOptimized(n, m);
    }
};
