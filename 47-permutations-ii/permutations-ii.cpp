class Solution {
private:
    void allPermute(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        if(idx>=nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i],nums[idx]);
            allPermute(nums,ans,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        allPermute(nums,ans,0);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};