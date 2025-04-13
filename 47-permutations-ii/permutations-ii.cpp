class Solution {
private:
    void findAns(int idx, set<vector<int>>& ans, vector<int>& nums) {
        if(idx == nums.size()) {
            ans.insert(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[idx], nums[i]);
            findAns(idx+1, ans, nums);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        findAns(0, ans, nums);
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};