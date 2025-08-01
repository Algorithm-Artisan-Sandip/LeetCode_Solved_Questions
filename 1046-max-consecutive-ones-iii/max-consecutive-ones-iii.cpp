class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int right = 0, left = 0;  // Sliding window pointers
        int maxLen = 0;           // Stores the maximum length of valid window
        int zeros = 0;            // Counts the number of zeros in the current window
        // Traverse the array with the right pointer
        while (right < arr.size()) {
            if (arr[right] == 0) zeros++;  // Count the zero encountered
            // If number of zeros exceeds k, shrink the window from the left
            // Move left pointer until zeros count is back to k
            if (zeros > k) {
                if (arr[left] == 0) zeros--;  // Reduce zero count when removing a 0 from the window
                left++;       // Shrink window from the left
            }
            // Update maxLen if current window has at most k zeros
            if (zeros <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;  // Expand the window to the right
        }
        return maxLen;  // Return the maximum window size found
    }
};
