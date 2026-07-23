class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        if (arr.empty()) return {};

        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> dp(n, 1);       // dp[i] stores the length of LIS ending at index i
        vector<int> parent(n, -1);   // Tracks the predecessor to rebuild the array
        
        int maxLength = 0;
        int lastIndex = 0;

        // Step 1: Compute DP array and track parents
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                // If it forms an increasing sequence AND gives a strictly longer sequence
                if (arr[i] % arr[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
            // Record the maximum length found and its ending index
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        // Step 2: Reconstruct the sequence backwards
        vector<int> result;
        int curr = lastIndex;
        while (curr != -1) {
            result.push_back(arr[curr]);
            curr = parent[curr];
        }

        // Reverse to restore chronological order
        reverse(result.begin(), result.end());
        return result;
    }
};