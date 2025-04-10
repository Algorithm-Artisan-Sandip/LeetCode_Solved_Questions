class Solution {
private:
    void findCombSum(int idx, int target, int n, vector<int> ans, set<vector<int>>& finalAns, vector<int> arr) {
        if(target == 0) {
            finalAns.insert(ans);
            return;
        }
        for(int i=idx; i<n; i++) {
            if(i>idx && arr[i] == arr[i-1]) continue;
            if(target < arr[i]) break;
            ans.push_back(arr[i]);
            findCombSum(i+1, target-arr[i], n, ans, finalAns, arr);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> finalAns;
        vector<int> ans;
        findCombSum(0, target, candidates.size(), ans, finalAns, candidates);
        vector<vector<int>> combSum(finalAns.begin(), finalAns.end());
        return combSum;
    }
};