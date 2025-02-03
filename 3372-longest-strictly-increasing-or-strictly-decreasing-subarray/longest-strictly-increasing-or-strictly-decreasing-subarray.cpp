class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int size = nums.size();
        int inc = 0, dec = 0;
        int longestInc = 0, longestDec = 0;
        int cnt = 0;
        for(int i=0; i<size-1; i++) {
            if(nums[i] < nums[i+1]) {
                inc++;
                longestInc = max(longestInc, inc);
            }
            else inc = 0;
        }
        for(int i=0; i<size-1; i++) {
            if(nums[i] > nums[i+1]) {
                dec++;
                longestDec = max(longestDec, dec);
            }
            else dec = 0;
        }

        return max(longestDec, longestInc) + 1;
    }
};