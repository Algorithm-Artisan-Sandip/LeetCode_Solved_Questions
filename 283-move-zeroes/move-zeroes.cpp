class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return;
        int nextPtr = 0;
        for(int i=0; i<size; i++) {
            if(nums[i] != 0) {
                swap(nums[nextPtr++], nums[i]);
            } 
        }
    }
};