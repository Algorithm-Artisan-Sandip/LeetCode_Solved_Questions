class Solution {
public:
    int findXorSum(vector<int>& nums, int idx, int xorSum) {
        if(idx==nums.size()) return xorSum;
        return findXorSum(nums,idx+1,xorSum^nums[idx]) + findXorSum(nums,idx+1,xorSum);
    }
    int subsetXORSum(vector<int>& nums) {
        return findXorSum(nums,0,0);
    }
};