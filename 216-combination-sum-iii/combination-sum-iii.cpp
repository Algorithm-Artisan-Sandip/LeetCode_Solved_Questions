class Solution {
private:
    void findCombSum(int idx, int maxLen, int target, vector<int> ans, vector<vector<int>>& finalAns, vector<int>& candidates) {
        if(target==0) {
            if(ans.size() == maxLen) finalAns.push_back(ans);
            return;
        }
 
        if(idx >= candidates.size()) return;
        if(target>=candidates[idx]) {
            ans.push_back(candidates[idx]);
            findCombSum(idx+1, maxLen, target-candidates[idx], ans, finalAns, candidates);
            ans.pop_back();
        }
        findCombSum(idx+1, maxLen, target, ans, finalAns, candidates);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for(int i=1; i<=9; i++) {
            candidates.push_back(i);
        }
        vector<int> ans;
        vector<vector<int>> finalAns;
        findCombSum(0, k, n, ans, finalAns, candidates);
        return finalAns;
    }
};