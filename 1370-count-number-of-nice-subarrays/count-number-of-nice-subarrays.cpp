class Solution {
  private:
    int countOdds(vector<int>& arr, int k) {
        int right = 0, left = 0;    // Window boundaries
        int subarrCnt = 0;          // Total valid subarrays
        int oddCnt = 0;             // Number of odds in current window
        // Slide the window across the array
        while (right < arr.size()) {
            // If current element is odd, increment odd count
            if (arr[right] & 1) 
                oddCnt++;
            // Shrink window from left until oddCnt ≤ k
            while (oddCnt > k) {
                if (arr[left] & 1)
                    oddCnt--;
                left++;
            }
            // All subarrays ending at 'right' with start from 'left' to 'right'
            // have ≤ k odd numbers, so add their count:
            subarrCnt += (right - left + 1);
            // Expand window to include next element
            right++;
        }
        return subarrCnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countOdds(nums, k) - countOdds(nums, k - 1);
    }
};