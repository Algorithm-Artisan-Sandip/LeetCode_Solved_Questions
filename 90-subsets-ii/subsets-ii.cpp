class Solution {
private:
    void findSubset(int idx, int n, vector<int> ans, set<vector<int>>& finalAns, vector<int> arr) {
        if(idx == n) {
            finalAns.insert(ans);
            return;
        }
        ans.push_back(arr[idx]);
        findSubset(idx+1, n, ans, finalAns, arr);
        ans.pop_back();
        findSubset(idx+1, n, ans, finalAns, arr);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        set<vector<int>> finalAns;
        findSubset(0, nums.size(), ans, finalAns, nums);
        vector<vector<int>> subsetAns(finalAns.begin(), finalAns.end());
        return subsetAns;
    }
};