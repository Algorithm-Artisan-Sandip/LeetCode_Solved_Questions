class Solution {
private:
    void findSubsets(int idx, int n, vector<int> ans, vector<vector<int>>&  finalAns, vector<int> arr) {
        if(idx == n) {
            finalAns.push_back(ans);
            return;
        }
        // take : 
        ans.push_back(arr[idx]);
        findSubsets(idx+1, n, ans, finalAns, arr);
        // not take : 
        ans.pop_back();
        findSubsets(idx+1, n, ans, finalAns, arr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        findSubsets(0, nums.size(), ans, finalAns, nums);
        return finalAns;
    }
};