class Solution {
public:
    int pivotElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Handle boundary cases to prevent out-of-bounds access
            if (mid > start && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            }
            if (mid < end && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            // Move towards the larger half
            if (nums[start] >= nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return 0;  // Return 0 if no pivot found (unrotated array)
    }

    int binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = pivotElement(nums);

        // Search in the first half (including the pivot) if the target is within its range
        if (target >= nums[0] || target <= nums[pivot]) {  // Use "||" instead of "&&"
            int result = binarySearch(nums, 0, pivot, target);
            if (result != -1 || target == nums[pivot]) {
                return result;
            }
        }

        // Otherwise, search in the second half
        return binarySearch(nums, pivot + 1, nums.size() - 1, target);
    }
};
