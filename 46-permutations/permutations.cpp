class Solution {
private:
    void findAns(int idx, vector<vector<int>>& finalAns, vector<int>& nums) {
        if(idx == nums.size()) {
            finalAns.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            findAns(idx+1, finalAns, nums);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> finalAns;
        findAns(0, finalAns, nums);
        return finalAns;
    }
};