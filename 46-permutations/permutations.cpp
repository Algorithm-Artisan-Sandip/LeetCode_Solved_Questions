class Solution {
private:
    void findAns(vector<int>& ans, vector<vector<int>>& finalAns, vector<int>& nums, unordered_map<int, int> freq) {
        if(ans.size() == nums.size()) {
            finalAns.push_back(ans);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!freq[nums[i]]) {
                ans.push_back(nums[i]);
                freq[nums[i]] = 1;
                findAns(ans, finalAns, nums, freq);
                freq[nums[i]] = 0;
                ans.pop_back(); 
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        unordered_map<int, int> freq;
        findAns(ans, finalAns, nums, freq);
        return finalAns;
    }
};