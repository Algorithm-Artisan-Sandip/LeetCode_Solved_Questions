class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size-2;
        while(i >=0 && nums[i+1] <= nums[i]) {
            i--;
        }
        if(i >= 0) {
            int j = size-1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};