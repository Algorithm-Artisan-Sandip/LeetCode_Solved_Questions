class Solution {
private:
    // Pure recursive solution (exponential time)
    // row, col: current position in the triangle
    // Returns minimum path sum from (row, col) down to the bottom
    int recursive(int row, int col, vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Base case: if we're at the last row, there's nowhere further to go
        if (row == n - 1) 
            return triangle[row][col];

        // Move down to the same column
        int justBelow = triangle[row][col] + recursive(row + 1, col, triangle);
        // Move down to the next column (diagonal right)
        int diagonalRight = triangle[row][col] + recursive(row + 1, col + 1, triangle);

        // Take the minimum of the two options
        return min(justBelow, diagonalRight);
    }

    // Top-down DP with memoization (O(n^2) time, O(n^2) space)
    // dp[row][col] stores the minimum path sum from (row, col) to bottom
    int memorization(int row, int col, vector<vector<int>>& triangle,
                     vector<vector<int>>& dp) {
        int n = triangle.size();
        // Base case: last row
        if (row == n - 1) 
            return triangle[row][col];
        // If already computed, return stored value
        if (dp[row][col] != -1) 
            return dp[row][col];

        // Compute the two choices
        int justBelow = triangle[row][col] + memorization(row + 1, col, triangle, dp);
        int diagonalRight = triangle[row][col] + memorization(row + 1, col + 1, triangle, dp);

        // Store and return minimum
        return dp[row][col] = min(justBelow, diagonalRight);
    }

    // Bottom-up DP tabulation (O(n^2) time and space)
    // Builds answers from the bottom row up to the top
    int tabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // dp[i][j] = minimum path sum from (i,j) down to bottom
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // 1) Initialize bottom row
        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // 2) Build DP values going upwards
        for (int i = n - 2; i >= 0; --i) {
            // Each row i has (i+1) elements
            for (int j = 0; j <= i; ++j) {
                // Two choices: down or down-right
                int down   = dp[i + 1][j];
                int downRt = dp[i + 1][j + 1];
                dp[i][j]   = triangle[i][j] + min(down, downRt);
            }
        }

        // 3) Result is at the top of the DP table
        return dp[0][0];
    }

    // Space-optimized DP (O(n^2) time, O(n) space)
    // Uses a single vector to represent the "previous" row's DP values
    int spaceOptimization(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Start with a copy of the bottom row as the initial DP state
        vector<int> dp = triangle[n - 1];

        // Move upwards, folding each row into dp
        for (int i = n - 2; i >= 0; --i) {
            // For row i, calculate dp[j] for j = 0..i
            for (int j = 0; j <= i; ++j) {
                int down   = dp[j];       // value from directly below
                int downRt = dp[j + 1];   // value from diagonal right below
                // update dp[j] in-place for the current row
                dp[j] = triangle[i][j] + min(down, downRt);
            }
            // After this, dp[0..i] holds results for row i
        }

        // dp[0] is the minimum path sum from the top to bottom
        return dp[0];
    }

public:
    // Entry point: choose desired approach by uncommenting
    int minimumTotal(vector<vector<int>>& triangle) {
        // 1) Pure recursion (slow)
        // return recursive(0, 0, triangle);

        // 2) Memoization (top-down DP)
        // int n = triangle.size();
        // vector<vector<int>> dp(n);
        // for (int i = 0; i < n; ++i) dp[i].assign(triangle[i].size(), -1);
        // return memorization(0, 0, triangle, dp);

        // 3) Tabulation (bottom-up DP)
        // return tabulation(triangle);

        // 4) Space-optimized DP
        return spaceOptimization(triangle);
    }
};
