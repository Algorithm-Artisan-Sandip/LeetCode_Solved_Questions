class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();

        for(int i=0; i<size; i++) while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i]) swap(nums[nums[i] - 1], nums[i]);

        for(int i=0; i<size; i++) if (nums[i] != i + 1) return i + 1;

        return size+1;
    }
};