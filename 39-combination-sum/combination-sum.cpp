class Solution {
private:
    void findCombSum(int idx, int target, int n, vector<int> ans, vector<vector<int>>& finalAns, vector<int> candidates) {
        if(idx==n) {
            if(target==0) {
                finalAns.push_back(ans);
            }
            return;
        }
        if(target >= candidates[idx]) {
            ans.push_back(candidates[idx]);
            findCombSum(idx, target-candidates[idx], n, ans, finalAns, candidates);
            ans.pop_back();
        }
        findCombSum(idx+1, target, n, ans, finalAns, candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        findCombSum(0, target, candidates.size(), ans, finalAns, candidates);
        return finalAns;
    }
};