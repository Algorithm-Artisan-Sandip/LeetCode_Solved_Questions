class Solution {
  private:
    int subarrFind(vector<int>& arr, int k) {
        // If k is zero, no subarray can have >0 distinct elements
        if (k == 0) return 0;
        int right = 0, left = 0;         // Window boundaries
        int subarrCnt = 0;              // Total count of valid subarrays
        unordered_map<int, int> mp;     // Tracks frequency of elements in window
        // Expand window by moving 'right'
        while (right < arr.size()) {
            mp[arr[right]]++;           // Include arr[right]
            // If window has more than k distinct, shrink from left
            if (mp.size() > k) {
                while (mp.size() > k) {
                    // Decrease count of arr[left], and remove if zero
                    if (--mp[arr[left]] == 0)
                        mp.erase(arr[left]);
                    left++;
                }
            }
            // All subarrays ending at 'right' with start from 'left' to 'right'
            // have ≤ k distinct elements, so add their count
            subarrCnt += (right - left + 1);

            right++;  // Move to next end
        }
        return subarrCnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrFind(nums, k) - subarrFind(nums, k - 1);
    }
};