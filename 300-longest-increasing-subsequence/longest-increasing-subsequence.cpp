class Solution {
public:
    // Tabulation Method (DP) : 

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // dp[i][prevIdx + 1]
        // Rows: 0 to n-1 (representing index i)
        // Columns: 0 to n (representing prevIdx + 1)
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        for (int i = 0; i < n; i++) {
            // prev can be -1, or any index to the right of i (i+1 to n-1)
            for (int prev = -1; prev < n; prev++) {
                if (prev != -1 && prev <= i) continue; // prev must be to the right of i

                // 1. Not Take Case (depends on the previous day's row processing: i - 1)
                int notTake = (i > 0) ? dp[i - 1][prev + 1] : 0;
                
                // 2. Take Case
                int take = 0;
                if (prev == -1 || nums[i] < nums[prev]) {
                    // If we take, the current 'i' becomes the 'prevIdx' for the next step
                    take = 1 + (i > 0 ? dp[i - 1][i + 1] : 0);
                }
                
                dp[i][prev + 1] = max(take, notTake);
            }
        }
        
        // The final answer is stored at the last element processed (n-1) with prev = -1 (index 0)
        return dp[n - 1][0];
    }
};