class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();

        int posIdx = 0, negIdx = 1;
        vector<int> ans(size);

        for(int i=0; i<size; i++) {
            if(nums[i]>0) {
                ans[posIdx] = nums[i];
                posIdx += 2;
            }
            else {
                ans[negIdx] = nums[i];
                negIdx += 2;
            }
        }

        return ans;
    }
};