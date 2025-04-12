class Solution {
private:
    void findAns(int idx, int n, vector<int>& ans, vector<vector<int>>& finalAns, vector<int>& arr) {
        finalAns.push_back(ans);
        for(int i=idx; i<n; i++) {
            if(i>idx && arr[i] == arr[i-1]) continue;
            ans.push_back(arr[i]);
            findAns(i+1, n, ans, finalAns, arr);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> finalAns;
        findAns(0, nums.size(), ans, finalAns, nums);
        return finalAns;
    }
};