class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        for(int i=0; i<size; i++) {
            if(nums[i] > nums[(i+1)%size]) cnt++; // using modulo for out of bound case
        }
        return cnt <= 1;
    }
};