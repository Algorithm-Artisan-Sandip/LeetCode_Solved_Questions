class Solution {
private:
    // Optimal DP solution using space optimization
    // Time Complexity: O(n), Space Complexity: O(1)
    int findAns(vector<int>& arr, int n) {
        // Base case: only one house to rob
        int prev1 = arr[0]; // dp[i-1]
        int prev2 = 0;      // dp[i-2]
        for (int i = 1; i <= n; i++) {
            // If we take current house, we must skip the previous one
            int take = arr[i] + prev2;
            // If we don't take current house, carry forward the previous max
            int notTake = prev1;
            // Current max profit
            int curr = max(take, notTake);
            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    // Main function to handle the circular street condition
    int rob(vector<int>& arr) {
        int n = arr.size();
        // Edge case: if only one house, rob it
        if (n == 1) return arr[0];
        // Create two subarrays:
        // temp1 excludes the first house
        // temp2 excludes the last house
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(arr[i]);       // from index 1 to n-1
            if (i != n - 1) temp2.push_back(arr[i]);   // from index 0 to n-2
        }
        // Compute max amount by either:
        // 1. Robbing from house 1 to n-1 (temp1)
        // 2. Robbing from house 0 to n-2 (temp2)
        int ans1 = findAns(temp1, n - 2); // n-2 because temp1 has size n-1, so last valid index is n-2
        int ans2 = findAns(temp2, n - 2); // same for temp2
        // Return the maximum of both cases
        return max(ans1, ans2);
    }
};
