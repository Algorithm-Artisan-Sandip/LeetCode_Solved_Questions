class Solution {
private:
    void findAns(int idx, vector<vector<int>>& ans, vector<int>& nums) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i=idx; i<nums.size(); i++) {
            if(used.count(nums[i])) continue;  // to avoid duplicate entires
            used.insert(nums[i]);
            swap(nums[idx], nums[i]);
            findAns(idx+1, ans, nums);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        findAns(0, ans, nums);
        return ans;
    }
};