class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=-1;
        
        for(int i=0; i<nums.size(); i++) if(nums[i]!=0) nums[++j] = nums[i];

        for(int i=j+1; i<nums.size(); i++) nums[i] = 0;
    }
};