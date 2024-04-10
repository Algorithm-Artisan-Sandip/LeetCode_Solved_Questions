class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        for(int i=0; i<size; i++) ans^=nums[i];
        return ans;
    }
};