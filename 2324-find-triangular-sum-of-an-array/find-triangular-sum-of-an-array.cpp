class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int temp = nums.size();
        for(int i=0; i<nums.size()-1; i++) {
            temp--;
            for(int j=0; j<temp; j++) {
                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
            nums[temp] = 0;
        }
        return nums[0];
    }
};