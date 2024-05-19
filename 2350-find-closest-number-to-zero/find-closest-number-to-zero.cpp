class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size();i++){
            int diff = abs(res - 0);
            int curr = abs(nums[i] - 0);

            if(curr < diff) res = nums[i];
            if(curr == diff) res = max(res, nums[i]);
        }
        return res;
    }
};