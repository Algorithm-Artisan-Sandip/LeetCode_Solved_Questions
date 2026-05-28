class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        vector<int> temp(k, -1);
        for(int i=size-k; i<size; i++) {
            temp[i-(size-k)] = nums[i];
        }
        for(int i=size-k-1; i>=0; i--) {
            nums[i+k] = nums[i];
        }
        for(int i=0; i<k; i++) {
            nums[i] = temp[i];
        }
    }
};