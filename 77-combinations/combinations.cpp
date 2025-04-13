class Solution {
private:
    void findAns(int idx, int k, vector<int>& arr, vector<int>& ans, vector<vector<int>>& finalAns) {
        if(ans.size() == k) {   // when the ans vector size is k simply sotre it and return
            finalAns.push_back(ans);
            return;
        }
        if(idx == arr.size()) return;  // edge case
        ans.push_back(arr[idx]);
        findAns(idx+1, k, arr, ans, finalAns);
        ans.pop_back();
        findAns(idx+1, k, arr, ans, finalAns);
    };
public:
    vector<vector<int>> combine(int n, int k) {
        // populate the array :
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = i+1;
        }
        vector<int> ans;
        vector<vector<int>> finalAns;
        findAns(0, k, arr, ans, finalAns);
        return finalAns;
    }
};