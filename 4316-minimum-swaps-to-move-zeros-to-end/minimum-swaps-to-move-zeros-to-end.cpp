class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
         int size = nums.size();
        if(size < 2) return 0;
        int zeroCnt = 0;
        for(int num : nums) {
            if(num == 0) zeroCnt++;
        }
        int swapCnt = 0;
        for(int i=size-zeroCnt; i<size; i++) {
            if(nums[i] != 0) swapCnt++;
        }
        return swapCnt;
    }
};