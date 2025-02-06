class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 2) return true;

        bool inc = false, dec = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc = true;
            } 
            else if (nums[i] < nums[i - 1]) {
                dec = true;
            }

            if(inc && dec) return false;
        }
        return true;
    }
};
