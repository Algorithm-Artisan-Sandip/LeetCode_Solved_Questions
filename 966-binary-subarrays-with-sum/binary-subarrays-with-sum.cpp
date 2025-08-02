class Solution {
  private:
    // Helper function to count the number of subarrays with sum at most 'target'
    int givenSumSubarray(vector<int>& arr, int target) {
        // If target is negative, it's not possible to have any subarray with such a sum
        if (target < 0) return 0;

        int right = 0, left = 0;
        int subArrCnt = 0; // To store the total number of valid subarrays
        int sum = 0;       // Current window sum

        // Use sliding window technique to count subarrays with sum ≤ target
        while (right < arr.size()) {
            // Include the current element in the window
            if (arr[right] == 1) sum++;

            // Shrink the window from the left until the sum becomes ≤ target
            while (sum > target) {
                if (arr[left] == 1)
                    sum--;
                left++;
            }

            // All subarrays from left to right are valid in this window
            subArrCnt += (right - left + 1);

            // Expand the window to the right
            right++;
        }

        return subArrCnt;
    }

  public:
    // Main function to count the number of subarrays with sum exactly equal to 'goal'
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        // Use inclusion-exclusion:
        // Count of subarrays with sum == goal
        // = Count of subarrays with sum ≤ goal
        // - Count of subarrays with sum ≤ goal - 1
        return givenSumSubarray(arr, goal) - givenSumSubarray(arr, goal - 1);
    }
};
