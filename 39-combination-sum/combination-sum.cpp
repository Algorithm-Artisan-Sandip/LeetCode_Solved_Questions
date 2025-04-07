class Solution {
private:
    void findCombSum(int idx, int target, int n, vector<int> ans, vector<vector<int>>& finalAns, vector<int> candidates) {
        if(idx == n) {
            if(target == 0) {  // if target is zero we found the valid combination
                finalAns.push_back(ans); 
            }
            return;
        }

        if(target >= candidates[idx]) {  // if target is greater or equal to the current element of array then only proceed
            ans.push_back(candidates[idx]); // push the current element
            findCombSum(idx, target - candidates[idx], n, ans, finalAns, candidates);  // taking the current element
            ans.pop_back();  // pop the current element
        }

        findCombSum(idx + 1, target, n, ans, finalAns, candidates); // not taking the current element
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;               
        vector<vector<int>> finalAns; 
        findCombSum(0, target, candidates.size(), ans, finalAns, candidates);
        return finalAns;
    }
};
