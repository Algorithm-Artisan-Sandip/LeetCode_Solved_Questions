class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int size = nums.size();

        int mid = nums[size/2];

        int ans = 0;
        for(int i=0; i<size; i++) ans += abs(mid-nums[i]);

        return ans;
    }
};