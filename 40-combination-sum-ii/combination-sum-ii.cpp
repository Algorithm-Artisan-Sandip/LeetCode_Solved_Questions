class Solution {
private:
    void findCombSum(int idx, int target, vector<int> ans, vector<vector<int>>& finalAns, vector<int>& candidates) {
        if(target == 0) {
            finalAns.push_back(ans);
            return;
        }
        for(int i=idx; i<candidates.size(); i++) {
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ans.push_back(candidates[i]);
            findCombSum(i+1, target-candidates[i], ans, finalAns, candidates);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        vector<vector<int>> finalAns;
        findCombSum(0, target, ans, finalAns, candidates);
        return finalAns;
    }
};