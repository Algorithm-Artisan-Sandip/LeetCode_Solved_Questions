#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // Ensure m <= n for efficient binary search
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0, right = m;

        // Binary search for the partition index in the shorter array (nums1)
        while (left <= right) {
            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            // Handle edge cases for empty arrays
            int max_left1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int min_right1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int max_left2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int min_right2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Check if partitions are correct
            if (max_left1 <= min_right2 && max_left2 <= min_right1) {
                // Find the median based on the total length
                if ((m + n) % 2 == 0) {
                    // Even number of elements: average of max_left and min_right
                    return (double)(max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0;
                } else {
                    // Odd number of elements: max from the larger partition
                    return (double)max(max_left1, max_left2);
                }
            } else if (max_left1 > min_right2) {
                // Adjust search to the left half of nums1
                right = partition1 - 1;
            } else {
                // Adjust search to the right half of nums1
                left = partition1 + 1;
            }
        }

        // Should not reach here (unreachable code)
        return 0.0;
    }
};
